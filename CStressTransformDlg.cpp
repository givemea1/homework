// CStressTransformDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ImageProcessing.h"
#include "afxdialogex.h"
#include "CStressTransformDlg.h"


// CStressTransformDlg 대화 상자

IMPLEMENT_DYNAMIC(CStressTransformDlg, CDialog)

CStressTransformDlg::CStressTransformDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG5, pParent)
	, m_StartPoint(0)
	, m_EndPoint(0)
{

}

CStressTransformDlg::~CStressTransformDlg()
{
}

void CStressTransformDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_StartPoint);
	DDV_MinMaxInt(pDX, m_StartPoint, 0, 255);
	DDX_Text(pDX, IDC_EDIT2, m_EndPoint);
	DDV_MinMaxInt(pDX, m_EndPoint, 0, 255);
}


BEGIN_MESSAGE_MAP(CStressTransformDlg, CDialog)
END_MESSAGE_MAP()


// CStressTransformDlg 메시지 처리기
