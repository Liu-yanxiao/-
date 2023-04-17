#pragma once


// Manager_Change2_Dlg 对话框

class Manager_Change2_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Manager_Change2_Dlg)

public:
	Manager_Change2_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Manager_Change2_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Manager_Change2_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	CString m_code;
};
