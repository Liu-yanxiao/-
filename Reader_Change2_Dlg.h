#pragma once


// Reader_Change2_Dlg 对话框

class Reader_Change2_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Reader_Change2_Dlg)

public:
	Reader_Change2_Dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Reader_Change2_Dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Reader_Change2_Dlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_code;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
