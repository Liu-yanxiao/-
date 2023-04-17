// Publisher_Login_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCbook.h"
#include "Publisher_Login_Dlg.h"
#include "afxdialogex.h"

#include "Publisher_Dlg.h"

// Publisher_Login_Dlg 对话框

IMPLEMENT_DYNAMIC(Publisher_Login_Dlg, CDialogEx)

Publisher_Login_Dlg::Publisher_Login_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Publisher_Login_Dlg, pParent)
	, m_code(_T(""))
{

}

Publisher_Login_Dlg::~Publisher_Login_Dlg()
{
}

void Publisher_Login_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_code);
}


BEGIN_MESSAGE_MAP(Publisher_Login_Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &Publisher_Login_Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Publisher_Login_Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Publisher_Login_Dlg 消息处理程序


void Publisher_Login_Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	EndDialog(0);
}


void Publisher_Login_Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	CStdioFile ReadFile;
	ReadFile.Open(_T(".\\Publisher_password.txt"), CFile::modeReadWrite);

	CString strData = _T(" ");

	ReadFile.ReadString(strData);
	ReadFile.Close();

	if (strData == m_code)
	{
		MessageBox(TEXT("登录成功！"), TEXT("提示"));

		Publisher_Dlg dlg;
		dlg.DoModal();

		EndDialog(0);
	}
	else
	{
		MessageBox(TEXT("密码错误，请重新输入"), TEXT("提示"));
	}

}
