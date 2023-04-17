#pragma once


// Manager_Dlg 对话框

class Manager_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Manager_Dlg)

public:
	Manager_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Manager_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Manager_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CListCtrl m_list;
	int m_num;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
};
