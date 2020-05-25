
// 实验8.2（2.1）View.cpp : C实验82（21）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "实验8.2（2.1）.h"
#endif

#include "实验8.2（2.1）Doc.h"
#include "实验8.2（2.1）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C实验82（21）View

IMPLEMENT_DYNCREATE(C实验82（21）View, CView)

BEGIN_MESSAGE_MAP(C实验82（21）View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// C实验82（21）View 构造/析构

C实验82（21）View::C实验82（21）View()
{
	// TODO: 在此处添加构造代码
	rect.top = 50;
	rect.bottom = 50;
	rect.left = 50;
	rect.right = 50;

}

C实验82（21）View::~C实验82（21）View()
{
}

BOOL C实验82（21）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C实验82（21）View 绘制

void C实验82（21）View::OnDraw(CDC* pDC)
{
	C实验82（21）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(rect);
	// TODO: 在此处为本机数据添加绘制代码
}


// C实验82（21）View 诊断

#ifdef _DEBUG
void C实验82（21）View::AssertValid() const
{
	CView::AssertValid();
}

void C实验82（21）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C实验82（21）Doc* C实验82（21）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C实验82（21）Doc)));
	return (C实验82（21）Doc*)m_pDocument;
}
#endif //_DEBUG


// C实验82（21）View 消息处理程序


void C实验82（21）View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
}


void C实验82（21）View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nFlags)
	{
		rect.top = point.y - 70;
		rect.bottom = point.y + 70;
		rect.left = point.y - 100;
		rect.right = point.y + 100;
		Invalidate();
	}
	CView::OnMouseMove(nFlags, point);
}
