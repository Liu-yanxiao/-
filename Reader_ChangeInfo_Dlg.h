#pragma once

extern CString a, b, c;

// Reader_ChangeInfo_Dlg 对话框

class Reader_ChangeInfo_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Reader_ChangeInfo_Dlg)

public:
	Reader_ChangeInfo_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Reader_ChangeInfo_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Reader_ChangeInfo_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_name;
	CString m_age;
	CString m_edu;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
