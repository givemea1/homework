
// imageproView.cpp: CimageproView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "imagepro.h"
#include "resource.h"
#endif

#include "imageproDoc.h"
#include "imageproView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CimageproView

IMPLEMENT_DYNCREATE(CimageproView, CScrollView)

BEGIN_MESSAGE_MAP(CimageproView, CScrollView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CimageproView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_PIXEL_ADD, &CimageproView::OnPixelAdd)
	ON_COMMAND(ID_PIXEL_SUB, &CimageproView::OnPixelSub)
	ON_COMMAND(ID_PIXEL_MUL, &CimageproView::OnPixelMul)
	ON_COMMAND(ID_PIXEL_DIV, &CimageproView::OnPixelDiv)
END_MESSAGE_MAP()

// CimageproView 생성/소멸

CimageproView::CimageproView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CimageproView::~CimageproView()
{
}

BOOL CimageproView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// CimageproView 그리기

void CimageproView::OnDraw(CDC* pDC)
{
	CimageproDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	for (int y = 0; y < 256;y++)
		for (int x = 0; x < 256;x++) {
			pDC->SetPixel(x, y, RGB(pDoc->inputImg[y][x],
				pDoc->inputImg[y][x],
				pDoc->inputImg[y][x]));
		}
	for (int y=0; y<256;y++)
		for (int x = 0; x < 256; x++) {
			pDC->SetPixel(x + 300, y, RGB(pDoc->resultImg[y][x],
				pDoc->resultImg[y][x], pDoc->resultImg[y][x]));
		}

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}

void CimageproView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.

	sizeTotal.cx = 2048;
	sizeTotal.cy = 1024;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CimageproView 인쇄


void CimageproView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CimageproView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CimageproView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CimageproView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CimageproView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CimageproView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CimageproView 진단

#ifdef _DEBUG
void CimageproView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CimageproView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CimageproDoc* CimageproView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CimageproDoc)));
	return (CimageproDoc*)m_pDocument;
}
#endif //_DEBUG


// CimageproView 메시지 처리기


void CimageproView::OnPixelAdd()
{
	CimageproDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->PixelAdd();

	Invalidate(FALSE);
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CimageproView::OnPixelSub()
{
	CimageproDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->PixelSub();

	Invalidate(FALSE);
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CimageproView::OnPixelMul()
{
	CimageproDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->PixelMul();

	Invalidate(FALSE);
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CimageproView::OnPixelDiv()
{
	CimageproDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->PixelDiv();

	Invalidate(FALSE);
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
