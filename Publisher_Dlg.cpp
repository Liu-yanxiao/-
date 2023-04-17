// Publisher_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCbook.h"
#include "Publisher_Dlg.h"
#include "afxdialogex.h"

#include "Publisher_Change_Dlg.h"
#include <locale.h>

// Publisher_Dlg 对话框

IMPLEMENT_DYNAMIC(Publisher_Dlg, CDialogEx)

Publisher_Dlg::Publisher_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Publisher_Dlg, pParent)
	, m_1(_T(""))
	, m_2(_T(""))
	, m_3(_T(""))
{

}

Publisher_Dlg::~Publisher_Dlg()
{
}

void Publisher_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT1, m_1);
	DDX_Text(pDX, IDC_EDIT2, m_2);
	DDX_Text(pDX, IDC_EDIT3, m_3);
}


BEGIN_MESSAGE_MAP(Publisher_Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Publisher_Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Publisher_Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Publisher_Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// Publisher_Dlg 消息处理程序


void Publisher_Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	Publisher_Change_Dlg dlg;
	dlg.DoModal();

	EndDialog(0);
}


BOOL Publisher_Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	CStdioFile ReadFile;
	char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));
	setlocale(LC_CTYPE, "chs");
	ReadFile.Open(_T(".\\Reader_Info.txt"), CFile::modeRead);
	CString strData1 = _T(" ");
	CString strData2 = _T(" ");
	CString strData3 = _T(" ");
	ReadFile.ReadString(strData1);
	ReadFile.ReadString(strData2);
	ReadFile.ReadString(strData3);
	ReadFile.Close();



	CString head[] = { TEXT("序号"),TEXT("名称"),TEXT("编码"),TEXT("简介") };
	//插入列标题
	m_list.InsertColumn(0, head[0], LVCFMT_LEFT, 50);
	m_list.InsertColumn(1, head[1], LVCFMT_LEFT, 120);
	m_list.InsertColumn(2, head[2], LVCFMT_LEFT, 80);
	m_list.InsertColumn(3, head[3], LVCFMT_LEFT, 250);

	CStdioFile file;  //构造对象
	unsigned int FileLine = 0;  //行数
	CString FileContent;  //行内容
	if (file.Open(_T(".\\Book.txt"), CStdioFile::modeRead) == false)
	{
		return false;
	}
	while (file.ReadString(FileContent))//获取文件的长度，到文件末尾时返回false；
	{
		FileLine++;
	}
	file.Close();

	FileLine = FileLine / 4;

	//CStdioFile ReadFile;

	ReadFile.Open(_T(".\\Book.txt"), CFile::modeRead);

	CString Con1[20], Con2[20], Con3[20], Con4[20];

	int num = 0;

	for (num = 0; num < FileLine; num++)
	{
		ReadFile.ReadString(Con1[num]);
		ReadFile.ReadString(Con2[num]);
		ReadFile.ReadString(Con3[num]);
		ReadFile.ReadString(Con4[num]);
	}

	ReadFile.ReadString(strData3);
	ReadFile.Close();
	setlocale(LC_CTYPE, old_locale); //还原语言区域的设置 
	free(old_locale);//还原区域设定

	for (int i = 0; i < FileLine; i++)
	{
		CString str;
		str.Format(TEXT("%d"), i + 1);
		m_list.InsertItem(i, str);
		m_list.SetItemText(i, 1, Con1[i]);
		m_list.SetItemText(i, 2, Con2[i]);
		m_list.SetItemText(i, 3, Con3[i]);
	}

	UpdateData(FALSE);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Publisher_Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	CStdioFile ReadFile;
	char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));
	setlocale(LC_CTYPE, "chs");
	ReadFile.Open(_T(".\\Reader_Info.txt"), CFile::modeRead);
	CString strData1 = _T(" ");
	CString strData2 = _T(" ");
	CString strData3 = _T(" ");
	ReadFile.ReadString(strData1);
	ReadFile.ReadString(strData2);
	ReadFile.ReadString(strData3);
	ReadFile.Close();

	CString str;
	str.Format(TEXT("借阅人信息：\n年龄：%s\n学历：%s"), strData2, strData3);
	MessageBox(str);

}


void Publisher_Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	CStdioFile myfile;
	char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));
	setlocale(LC_CTYPE, "chs");
	myfile.Open(_T("Book.txt"), CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate);
	myfile.SeekToEnd();
	myfile.WriteString(m_1);
	myfile.WriteString(TEXT("\n"));
	myfile.WriteString(m_2);
	myfile.WriteString(TEXT("\n"));
	myfile.WriteString(m_3);
	myfile.WriteString(TEXT("\n"));
	myfile.WriteString(TEXT("0"));
	myfile.WriteString(TEXT("\n"));
	myfile.Close();
	setlocale(LC_CTYPE, old_locale); //还原语言区域的设置 
	free(old_locale);//还原区域设定

	MessageBox(TEXT("信息变动，请重新登录！"));

	EndDialog(0);
}
