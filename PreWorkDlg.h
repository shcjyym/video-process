
// PreWorkDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

// CPreWorkDlg �Ի���
class CPreWorkDlg : public CDialogEx
{
// ����
public:
	CPreWorkDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PREWORK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCutvideo();
	afx_msg void OnEnChangeOpenfile();
	afx_msg void OnBnClickedCutmat();
	afx_msg void OnEnChangeRow();
	afx_msg void OnEnChangeColumn();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnBnClickedCancel();
	afx_msg void OnStnClickedClose();
	afx_msg void OnStnClickedMin();
	afx_msg void OnEnChangeOpenfile2();
	CStatic m_min;
	CFont newFont_1,newFont_2;
	CStatic m_close;
	CButton m_transform;
};
