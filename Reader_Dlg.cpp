// Reader_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCbook.h"
#include "Reader_Dlg.h"
#include "afxdialogex.h"

#include "Reader_Change_Dlg.h"
#include "Reader_ChangeInfo_Dlg.h"

#include <locale.h>

// Reader_Dlg 对话框

IMPLEMENT_DYNAMIC(Reader_Dlg, CDialogEx)

Reader_Dlg::Reader_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Reader_Dlg, pParent)
	, m_name(_T(""))
	, m_age(_T(""))
	, m_edu(_T(""))
	, m_num(0)
	, m_add(0)
	, m_del(0)
{

}

Reader_Dlg::~Reader_Dlg()
{
}

void Reader_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_age);
	DDX_Text(pDX, IDC_EDIT3, m_edu);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT4, m_num);
	//  DDX_Text(pDX, IDC_EDIT5, m_name1);
	//  DDX_Text(pDX, IDC_EDIT6, m_name2);
	DDX_Text(pDX, IDC_EDIT5, m_add);
	DDX_Text(pDX, IDC_EDIT6, m_del);
}


BEGIN_MESSAGE_MAP(Reader_Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Reader_Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Reader_Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Reader_Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Reader_Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// Reader_Dlg 消息处理程序


void Reader_Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码


	Reader_Change_Dlg dlg;
	dlg.DoModal();
	EndDialog(0);

}


BOOL Reader_Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_num = 0;
	//UpdateData(TRUE);

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


	m_name = strData1;
	m_age = strData2;
	m_edu = strData3;

	CString head[] = { TEXT("序号"),TEXT("名称"),TEXT("编码"),TEXT("简介"),TEXT("借阅情况")};
	//插入列标题
	m_list.InsertColumn(0, head[0], LVCFMT_LEFT, 50);
	m_list.InsertColumn(1, head[1], LVCFMT_LEFT, 120);
	m_list.InsertColumn(2, head[2], LVCFMT_LEFT, 80);
	m_list.InsertColumn(3, head[3], LVCFMT_LEFT, 200);
	m_list.InsertColumn(4, head[4], LVCFMT_LEFT, 80);

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

	for(num = 0 ; num < FileLine ; num ++)
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
		str.Format(TEXT("%d"), i+1);
		m_list.InsertItem(i, str);
		m_list.SetItemText(i, 1,Con1[i]);
		m_list.SetItemText(i, 2, Con2[i]);
		m_list.SetItemText(i, 3, Con3[i]);
		CString a = Con4[i].Right(1);
		if (Con4[i].Right(1) == "1")
		{
			m_list.SetItemText(i, 4, TEXT("已借阅"));
			m_num++;
		}
		else m_list.SetItemText(i, 4, TEXT("未借阅"));
	}

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

CString a, b, c;

void Reader_Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	Reader_ChangeInfo_Dlg dlg;
	dlg.DoModal();

	m_name = a;
	m_age = b;
	m_edu = c;

	UpdateData(FALSE);

}


void Reader_Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	CStdioFile newFile;
	CStdioFile oldFile;
	newFile.Open(_T(".\\temp.txt"), CFile::typeText | CFile::modeCreate | CFile::modeReadWrite | CFile::modeNoTruncate);
	oldFile.Open(_T(".\\Book.txt"), CFile::typeText | CFile::modeCreate | CFile::modeReadWrite | CFile::modeNoTruncate);
	char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));
	_tsetlocale(LC_CTYPE, _T("chs"));//CStdioFile默认的本地语言是英文  设置为简体中文
	CString str;

	for (int i = 0; i < ((m_add-1) * 4); i++)
	{
		oldFile.ReadString(str);
		newFile.WriteString(str);
		newFile.WriteString(_T("\n"));
	}

	oldFile.ReadString(str);
	newFile.WriteString(str);
	newFile.WriteString(_T("\n"));
	oldFile.ReadString(str);
	newFile.WriteString(str);
	newFile.WriteString(_T("\n"));
	oldFile.ReadString(str);
	newFile.WriteString(str);
	newFile.WriteString(_T("\n"));

	newFile.WriteString(_T("1"));
	newFile.WriteString(_T("\n"));

	oldFile.ReadString(str);
	while (oldFile.ReadString(str))//将剩下的所有行依依写入到新文件中
	{
		str += _T("\n");
		newFile.WriteString(str);
	}

	free(old_locale);//还原区域设定
	oldFile.Close();
	newFile.Close();
	oldFile.Remove(_T("Book.txt"));
	newFile.Rename(_T("temp.txt"), _T("Book.txt"));

	MessageBox(TEXT("信息变动，请重新登录！"));

	EndDialog(0);

}


void Reader_Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	CStdioFile newFile;
	CStdioFile oldFile;
	newFile.Open(_T(".\\temp.txt"), CFile::typeText | CFile::modeCreate | CFile::modeReadWrite | CFile::modeNoTruncate);
	oldFile.Open(_T(".\\Book.txt"), CFile::typeText | CFile::modeCreate | CFile::modeReadWrite | CFile::modeNoTruncate);
	char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));
	_tsetlocale(LC_CTYPE, _T("chs"));//CStdioFile默认的本地语言是英文  设置为简体中文
	CString str;

	for (int i = 0; i < ((m_del - 1) * 4); i++)
	{
		oldFile.ReadString(str);
		newFile.WriteString(str);
		newFile.WriteString(_T("\n"));
	}

	oldFile.ReadString(str);
	newFile.WriteString(str);
	newFile.WriteString(_T("\n"));
	oldFile.ReadString(str);
	newFile.WriteString(str);
	newFile.WriteString(_T("\n"));
	oldFile.ReadString(str);
	newFile.WriteString(str);
	newFile.WriteString(_T("\n"));

	newFile.WriteString(_T("0"));
	newFile.WriteString(_T("\n"));

	oldFile.ReadString(str);
	while (oldFile.ReadString(str))//将剩下的所有行依依写入到新文件中
	{
		str += _T("\n");
		newFile.WriteString(str);
	}

	free(old_locale);//还原区域设定
	oldFile.Close();
	newFile.Close();
	oldFile.Remove(_T("Book.txt"));
	newFile.Rename(_T("temp.txt"), _T("Book.txt"));

	MessageBox(TEXT("信息变动，请重新登录！"));

	EndDialog(0);

}
