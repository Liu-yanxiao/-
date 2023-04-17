// Reader_ChangeInfo_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCbook.h"
#include "Reader_ChangeInfo_Dlg.h"
#include "afxdialogex.h"

#include <locale.h>

// Reader_ChangeInfo_Dlg 对话框

IMPLEMENT_DYNAMIC(Reader_ChangeInfo_Dlg, CDialogEx)

Reader_ChangeInfo_Dlg::Reader_ChangeInfo_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Reader_ChangeInfo_Dlg, pParent)
	, m_name(_T(""))
	, m_age(_T(""))
	, m_edu(_T(""))
{

}

Reader_ChangeInfo_Dlg::~Reader_ChangeInfo_Dlg()
{
}

void Reader_ChangeInfo_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_age);
	DDX_Text(pDX, IDC_EDIT3, m_edu);
}


BEGIN_MESSAGE_MAP(Reader_ChangeInfo_Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &Reader_ChangeInfo_Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Reader_ChangeInfo_Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Reader_ChangeInfo_Dlg 消息处理程序


void Reader_ChangeInfo_Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	EndDialog(0);
}


void Reader_ChangeInfo_Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	a = m_name;
	b = m_age;
	c = m_edu;

	CStdioFile WriteFile;
	char* old_locale = _strdup(setlocale(LC_CTYPE, NULL));
	setlocale(LC_CTYPE, "chs");
	WriteFile.Open(_T(".\\Reader_Info.txt"), CFile::modeWrite | CFile::modeRead | CFile::modeCreate);
	WriteFile.WriteString(m_name);
	WriteFile.WriteString(TEXT("\n"));
	WriteFile.WriteString(m_age);
	WriteFile.WriteString(TEXT("\n"));
	WriteFile.WriteString(m_edu);
	WriteFile.Close();
	setlocale(LC_CTYPE, old_locale); //还原语言区域的设置 
	free(old_locale);//还原区域设定

	EndDialog(0);
}
