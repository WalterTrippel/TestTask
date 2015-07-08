
// TestTaskView.cpp : implementation of the CTestTaskView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TestTask.h"
#endif

#include "TestTaskDoc.h"
#include "TestTaskView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestTaskView

IMPLEMENT_DYNCREATE(CTestTaskView, CScrollView)

BEGIN_MESSAGE_MAP(CTestTaskView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)

	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CTestTaskView construction/destruction

CTestTaskView::CTestTaskView() :_previous(0, 0), _end(0, 0), _width(1000), _height(1000)
{
	// TODO: add construction code here

}

CTestTaskView::~CTestTaskView()
{
}

BOOL CTestTaskView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CTestTaskView drawing

void CTestTaskView::OnDraw(CDC* pDC)
{
	CTestTaskDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
	{
		return;
	}

	CRect rect(_previous, _end);
	pDC->MoveTo(_previous);
	pDC->LineTo(_end);
}

void CTestTaskView::OnMouseMove(UINT flags, CPoint point)
{
	if (GetCapture() == this)
	{
		CPoint tmp = GetDeviceScrollPosition();
		CPoint buff = _end - tmp;
		_end = point;

		CRect rect;
		GetWindowRect(&rect);

		CPoint vec = CPoint(0, 0);
		if ((_end.x > (rect.right - rect.left) || _end.x < 0) || (_end.y >(rect.bottom - rect.top) || _end.y < 0))
		{
			CPoint the_line = _end - _previous;
			if (_end.x > (rect.right - rect.left) || _end.x < 0)
			{
				if (the_line.y < 0)
					vec = CPoint(0, -1);
				else
					vec = CPoint(0, 1);
			}
			else if (_end.y > (rect.bottom - rect.top) || _end.y < 0)
			{
				if (the_line.x > 0)
					vec = CPoint(1, 0);
				else
					vec = CPoint(-1, 0);
			}

			double alpha = acos((double)(walter::scalar_multiplication(the_line, vec) /
				(walter::length(the_line) * walter::length(vec))));

			CPoint shift_scroll = walter::const_multiplication(the_line, cos(alpha));

			if (shift_scroll != CPoint(0, 0))
			{
				walter::normalize(shift_scroll);
				ScrollToPosition(GetScrollPosition() + shift_scroll);
			}
		}
		
		_end += tmp;
		Invalidate();
	}
}

void CTestTaskView::OnLButtonUp(UINT flags, CPoint point)
{
	if (GetCapture() == this)
	{
		ReleaseCapture();
		CPoint tmp = GetDeviceScrollPosition();
		_end = point + tmp;
		Invalidate();
	}
}

void CTestTaskView::OnLButtonDown(UINT flags, CPoint point)
{
	CPoint tmp = GetDeviceScrollPosition();
	_previous = point + tmp;
	SetCapture();
}

void CTestTaskView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	CRect rect;
	GetWindowRect(&rect);
	sizeTotal = rect.Size();
	SetScrollSizes(MM_TEXT, /*sizeTotal*/ CSize(_width, _height));
}


// CTestTaskView printing

BOOL CTestTaskView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestTaskView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestTaskView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CTestTaskView diagnostics

#ifdef _DEBUG
void CTestTaskView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CTestTaskView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CTestTaskDoc* CTestTaskView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestTaskDoc)));
	return (CTestTaskDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestTaskView message handlers
