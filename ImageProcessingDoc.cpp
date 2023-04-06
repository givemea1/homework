
// imageproDoc.cpp: CimageproDoc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "imagepro.h"
#endif

#include "imageproDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CimageproDoc

IMPLEMENT_DYNCREATE(CimageproDoc, CDocument)

BEGIN_MESSAGE_MAP(CimageproDoc, CDocument)
END_MESSAGE_MAP()


// CimageproDoc 생성/소멸

CimageproDoc::CimageproDoc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CimageproDoc::~CimageproDoc()
{
}

BOOL CimageproDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CimageproDoc serialization

void CimageproDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring() == TRUE)
	{
		ar.Write(resultImg, 256 * 256);
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		CFile* fp = ar.GetFile();
		if (fp->GetLength() == 256 * 256)ar.Read(inputImg, 256 * 256);
		else AfxMessageBox("256*256 크기의 파일만 사용가능합니다.");
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CimageproDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CimageproDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CimageproDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CimageproDoc 진단

#ifdef _DEBUG
void CimageproDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CimageproDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CimageproDoc 명령


void CimageproDoc::PixelAdd(void)
{
	int value = 0;

	for(int x=0;x<256;x++)
		for (int y = 0; y < 256;y++) {
			value = inputImg[x][y] + 100;
			if (value > 255) resultImg[x][y] = 255;
			else resultImg[x][y] = value;
		}
	// TODO: 여기에 구현 코드 추가.
}


void CimageproDoc::PixelSub()
{
	int value = 0;

	for(int x=0;x<256;x++)
		for (int y = 0;y < 256;y++) {
			value = inputImg[x][y] - 100;
			if (value < 0)resultImg[x][y] = 0;
			else resultImg[x][y] = value;
		}
	// TODO: 여기에 구현 코드 추가.
}


void CimageproDoc::PixelMul()
{
	int value = 0;

	for (int x = 0;x < 256;x++)
		for (int y = 0;y < 256;y++) {
			value = inputImg[x][y] * 2;
			if (value > 255)resultImg[x][y] = 255;
			else resultImg[x][y] = value;
		}

	// TODO: 여기에 구현 코드 추가.
}


void CimageproDoc::PixelDiv()
{
	int value = 0;

	for (int x = 0;x < 256;x++)
		for (int y = 0;y < 256;y++) {
			value = inputImg[x][y] / 2;
			if (value < 0)resultImg[x][y] = 0;
			else resultImg[x][y] = value;
		}
	// TODO: 여기에 구현 코드 추가.
}
