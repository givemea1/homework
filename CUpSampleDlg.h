#pragma once
#include "afxdialogex.h"


// CUpSampleDlg 대화 상자

class CUpSampleDlg : public CDialog
{
	DECLARE_DYNAMIC(CUpSampleDlg)

public:
	CUpSampleDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CUpSampleDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG21 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_UpSampleRate;
};
