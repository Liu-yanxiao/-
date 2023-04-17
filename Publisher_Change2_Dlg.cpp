// Publisher_Change2_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCbook.h"
#include "Publisher_Change2_Dlg.h"
#include "afxdialogex.h"


// Publisher_Change2_Dlg 对话框

IMPLEMENT_DYNAMIC(Publisher_Change2_Dlg, CDialogEx)

Publisher_Change2_Dlg::Publisher_Change2_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Publisher_Change2_Dlg, pParent)
	, m_code(_T(""))
{

}

Publisher_Change2_Dlg::~Publisher_Change2_Dlg()
{
}

void Publisher_Change2_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_code);
}


BEGIN_MESSAGE_MAP(Publisher_Change2_Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &Publisher_Change2_Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Publisher_Change2_Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Publisher_Change2_Dlg 消息处理程序


void Publisher_Change2_Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	EndDialog(0);

}


void Publisher_Change2_Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	CStdioFile WriteFile;
	WriteFile.Open(_T(".\\Publisher_password.txt"), CFile::modeWrite | CFile::modeRead | CFile::modeCreate);
	WriteFile.WriteString(m_code);
	WriteFile.Close();

	MessageBox(TEXT("修改成功，请您重新登录！"));

	EndDialog(0);

}
