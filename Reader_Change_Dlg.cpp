// Reader_Change_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCbook.h"
#include "Reader_Change_Dlg.h"
#include "afxdialogex.h"

#include "Reader_Dlg.h"
#include "Reader_Change2_Dlg.h"

// Reader_Change_Dlg 对话框

IMPLEMENT_DYNAMIC(Reader_Change_Dlg, CDialogEx)

Reader_Change_Dlg::Reader_Change_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Reader_Change_Dlg, pParent)
	, m_code(_T(""))
{

}

Reader_Change_Dlg::~Reader_Change_Dlg()
{
}

void Reader_Change_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_code);
}


BEGIN_MESSAGE_MAP(Reader_Change_Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Reader_Change_Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Reader_Change_Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// Reader_Change_Dlg 消息处理程序


void Reader_Change_Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	CStdioFile ReadFile;
	ReadFile.Open(_T(".\\Reader_password.txt"), CFile::modeReadWrite);
	CString strData = _T(" ");
	ReadFile.ReadString(strData);
	ReadFile.Close();

	if (strData == m_code)
	{
		//MessageBox(TEXT("登录成功！"), TEXT("提示"));
		Reader_Change2_Dlg dlg;
		dlg.DoModal();
		EndDialog(0);
	}
	else
	{
		MessageBox(TEXT("密码错误，请重新输入"), TEXT("提示"));
	}
}


void Reader_Change_Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码



	EndDialog(0);
}
