
// 实验8.2（2.3)View.cpp : C实验82（23View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "实验8.2（2.3).h"
#endif

#include "实验8.2（2.3)Doc.h"
#include "实验8.2（2.3)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C实验82（23View

IMPLEMENT_DYNCREATE(C实验82（23View, CView)

BEGIN_MESSAGE_MAP(C实验82（23View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C实验82（23View 构造/析构

C实验82（23View::C实验82（23View()
{
	// TODO: 在此处添加构造代码
	rect.top = 100;
	rect.bottom = 300;
	rect.left = 200;
	rect.right = 500;
	x1 = rect.left;
	x2 = rect.right;
	y1 = rect.top;
	y2 = rect.bottom;
}

C实验82（23View::~C实验82（23View()
{
}

BOOL C实验82（23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C实验82（23View 绘制

void C实验82（23View::OnDraw(CDC* pDC)
{
	C实验82（23Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(rect);
	// TODO: 在此处为本机数据添加绘制代码
}


// C实验82（23View 诊断

#ifdef _DEBUG
void C实验82（23View::AssertValid() const
{
	CView::AssertValid();
}

void C实验82（23View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C实验82（23Doc* C实验82（23View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C实验82（23Doc)));
	return (C实验82（23Doc*)m_pDocument;
}
#endif //_DEBUG


// C实验82（23View 消息处理程序


void C实验82（23View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	if (point.x > x1&&point.x<x2&& point.y>y1 && point.y < y2)
	{
		CPen newPen(PS_DASH, 1, RGB(0, 0, 255));
		CPen* oldPen = dc.SelectObject(&newPen);
		dc.SelectStockObject(NULL_BRUSH);
		dc.Rectangle(rect);
	}
	CView::OnLButtonDown(nFlags, point);
}
