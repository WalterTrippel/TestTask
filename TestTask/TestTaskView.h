
// TestTaskView.h : interface of the CTestTaskView class
//

#include "Math.h"

#pragma once


class CTestTaskView : public CScrollView
{
private:
	CPoint _previous;
	CPoint _end;

	int _width;
	int _height;
protected: // create from serialization only
	CTestTaskView();
	DECLARE_DYNCREATE(CTestTaskView)

// Attributes
public:
	CTestTaskDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnLButtonDown(UINT flags, CPoint point);
	virtual void OnLButtonUp(UINT flags, CPoint point);
	virtual void OnMouseMove(UINT flags, CPoint point);
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CTestTaskView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TestTaskView.cpp
inline CTestTaskDoc* CTestTaskView::GetDocument() const
   { return reinterpret_cast<CTestTaskDoc*>(m_pDocument); }
#endif

