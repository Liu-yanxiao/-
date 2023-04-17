// Reader_Change2_Dlg.cpp: 实现文件
//

#include "pch.h"
#include "MFCbook.h"
#include "Reader_Change2_Dlg.h"
#include "afxdialogex.h"


// Reader_Change2_Dlg 对话框

IMPLEMENT_DYNAMIC(Reader_Change2_Dlg, CDialogEx)

Reader_Change2_Dlg::Reader_Change2_Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Reader_Change2_Dlg, pParent)
	, m_code(_T(""))
{

}

Reader_Change2_Dlg::~Reader_Change2_Dlg()
{
}

void Reader_Change2_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_code);
}


BEGIN_MESSAGE_MAP(Reader_Change2_Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &Reader_Change2_Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Reader_Change2_Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Reader_Change2_Dlg 消息处理程序


void Reader_Change2_Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	EndDialog(0);
}


void Reader_Change2_Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);

	CStdioFile WriteFile;
	WriteFile.Open(_T(".\\Reader_password.txt"), CFile::modeWrite | CFile::modeRead | CFile::modeCreate);
	WriteFile.WriteString(m_code);
	WriteFile.Close();

	MessageBox(TEXT("修改成功，请您重新登录！"));

	EndDialog(0);
}
