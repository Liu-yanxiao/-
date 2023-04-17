#pragma once


// Reader_Dlg 对话框

class Reader_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Reader_Dlg)

public:
	Reader_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Reader_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Reader_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString m_name;
	CString m_age;
	CString m_edu;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	CListCtrl m_list;
	afx_msg void OnBnClickedButton3();
	int m_num;
//	CString m_name1;
//	CString m_name2;
	int m_add;
	int m_del;
	afx_msg void OnBnClickedButton4();
};
