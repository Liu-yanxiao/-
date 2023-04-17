// Manager_Change_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCbook.h"
#include "Manager_Change_Dlg.h"
#include "afxdialogex.h"

#include "Manager_Change2_Dlg.h"

// Manager_Change_Dlg 对话框

IMPLEMENT_DYNAMIC(Manager_Change_Dlg, CDialogEx)

Manager_Change_Dlg::Manager_Change_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Manager_Change_Dlg, pParent)
	, m_code(_T(""))
{

}

Manager_Change_Dlg::~Manager_Change_Dlg()
{
}

void Manager_Change_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_code);
}


BEGIN_MESSAGE_MAP(Manager_Change_Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &Manager_Change_Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Manager_Change_Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Manager_Change_Dlg 消息处理程序


void Manager_Change_Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	EndDialog(0);

}


void Manager_Change_Dlg::OnBnClickedButton1()
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
		Manager_Change2_Dlg dlg;
		dlg.DoModal();
		EndDialog(0);
	}
	else
	{
		MessageBox(TEXT("密码错误，请重新输入"), TEXT("提示"));
	}

}
