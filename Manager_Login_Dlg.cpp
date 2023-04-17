// Manager_Login_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCbook.h"
#include "Manager_Login_Dlg.h"
#include "afxdialogex.h"

#include "Manager_Dlg.h"

// Manager_Login_Dlg 对话框

IMPLEMENT_DYNAMIC(Manager_Login_Dlg, CDialogEx)

Manager_Login_Dlg::Manager_Login_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Manager_Login_Dlg, pParent)
	, m_code(_T(""))
{

}

Manager_Login_Dlg::~Manager_Login_Dlg()
{
}

void Manager_Login_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_code);
}


BEGIN_MESSAGE_MAP(Manager_Login_Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Manager_Login_Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Manager_Login_Dlg 消息处理程序


void Manager_Login_Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	CStdioFile ReadFile;
	ReadFile.Open(_T(".\\Manager_password.txt"), CFile::modeReadWrite);

	CString strData = _T(" ");

	ReadFile.ReadString(strData);
	ReadFile.Close();

	if (strData == m_code)
	{
		//MessageBox(TEXT("登录成功！"), TEXT("提示"));

		Manager_Dlg dlg;
		dlg.DoModal();

		EndDialog(0);
	}
	else
	{
		MessageBox(TEXT("密码错误，请重新输入"), TEXT("提示"));
	}

}
