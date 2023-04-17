#pragma once


// Manager_Login_Dlg 对话框

class Manager_Login_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Manager_Login_Dlg)

public:
	Manager_Login_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Manager_Login_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Manager_Login_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_code;
};
