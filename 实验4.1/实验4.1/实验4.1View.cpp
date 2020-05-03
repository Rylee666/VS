
// 实验4.1View.cpp : C实验41View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "实验4.1.h"
#endif

#include "实验4.1Doc.h"
#include "实验4.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C实验41View

IMPLEMENT_DYNCREATE(C实验41View, CView)

BEGIN_MESSAGE_MAP(C实验41View, CView)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// C实验41View 构造/析构

C实验41View::C实验41View()
{
	// TODO: 在此处添加构造代码

}

C实验41View::~C实验41View()
{
}

BOOL C实验41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C实验41View 绘制

void C实验41View::OnDraw(CDC* pDC)
{
	C实验41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->m_tagRec);
	// TODO: 在此处为本机数据添加绘制代码
}


// C实验41View 诊断

#ifdef _DEBUG
void C实验41View::AssertValid() const
{
	CView::AssertValid();
}

void C实验41View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C实验41Doc* C实验41View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C实验41Doc)));
	return (C实验41Doc*)m_pDocument;
}
#endif //_DEBUG


// C实验41View 消息处理程序


void C实验41View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C实验41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->m_tagRec.right = point.x;
	pDoc->m_tagRec.bottom = point.y;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonUp(nFlags, point);
}


void C实验41View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C实验41Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->m_tagRec.left = point.x;
	pDoc->m_tagRec.top = point.y;
	InvalidateRect(NULL, TRUE);
	CView::OnLButtonDown(nFlags, point);
}


void C实验41View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s;
	s.Format(_T("%d,%d"), point.x, point.y);
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnMouseMove(nFlags, point);
}
