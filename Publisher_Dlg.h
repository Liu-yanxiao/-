#pragma once


// Publisher_Dlg 对话框

class Publisher_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Publisher_Dlg)

public:
	Publisher_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Publisher_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Publisher_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CListCtrl m_list;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	CString m_1;
	CString m_2;
	CString m_3;
	afx_msg void OnBnClickedButton3();
};
