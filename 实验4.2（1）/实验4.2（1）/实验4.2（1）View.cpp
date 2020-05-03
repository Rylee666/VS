
// 实验4.2（1）View.cpp : C实验42（1）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "实验4.2（1）.h"
#endif

#include "实验4.2（1）Doc.h"
#include "实验4.2（1）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C实验42（1）View

IMPLEMENT_DYNCREATE(C实验42（1）View, CView)

BEGIN_MESSAGE_MAP(C实验42（1）View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// C实验42（1）View 构造/析构

C实验42（1）View::C实验42（1）View()
{
	// TODO: 在此处添加构造代码

}

C实验42（1）View::~C实验42（1）View()
{
}

BOOL C实验42（1）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C实验42（1）View 绘制
int count = 0;
int num = 0;
CPoint apoint, bpoint;
CString s, s1;
void C实验42（1）View::OnDraw(CDC* /*pDC*/)
{
	C实验42（1）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C实验42（1）View 诊断

#ifdef _DEBUG
void C实验42（1）View::AssertValid() const
{
	CView::AssertValid();
}

void C实验42（1）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C实验42（1）Doc* C实验42（1）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C实验42（1）Doc)));
	return (C实验42（1）Doc*)m_pDocument;
}
#endif //_DEBUG


// C实验42（1）View 消息处理程序


void C实验42（1）View::OnLButtonDown(UINT nFlags, CPoint point)
{
	bpoint.x = point.x;
	CView::OnLButtonDown(nFlags, point);
}


void C实验42（1）View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	count = 0;
	apoint.x = point.x;
	if (apoint.x > bpoint.x)
		num = apoint.x - bpoint.x;
	if (apoint.x <bpoint.x)
		num = bpoint.x - apoint.x;
	if (apoint.x == bpoint.x)
		num = 0;
	s.Format(_T("移动的像素：%d"), num);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonUp(nFlags, point);
}


void C实验42（1）View::OnMouseMove(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	if (nFlags)
	{
		s1.Format(_T("鼠标移动的次数：%d"), count++);
		dc.TextOutW(100, 100, s1);
	}
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnMouseMove(nFlags, point);
}
