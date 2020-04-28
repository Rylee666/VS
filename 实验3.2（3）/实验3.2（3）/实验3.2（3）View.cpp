
// 实验3.2（3）View.cpp : C实验32（3）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "实验3.2（3）.h"
#endif

#include "实验3.2（3）Doc.h"
#include "实验3.2（3）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C实验32（3）View

IMPLEMENT_DYNCREATE(C实验32（3）View, CView)

BEGIN_MESSAGE_MAP(C实验32（3）View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C实验32（3）View 构造/析构

C实验32（3）View::C实验32（3）View()
{
	// TODO: 在此处添加构造代码

}

C实验32（3）View::~C实验32（3）View()
{
}

BOOL C实验32（3）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C实验32（3）View 绘制

void C实验32（3）View::OnDraw(CDC* pDC)
{
	C实验32（3）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->ca);
	pDC->Rectangle(pDoc->cb);
	pDC->Rectangle(pDoc->cc);
	// TODO: 在此处为本机数据添加绘制代码
}


// C实验32（3）View 诊断

#ifdef _DEBUG
void C实验32（3）View::AssertValid() const
{
	CView::AssertValid();
}

void C实验32（3）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C实验32（3）Doc* C实验32（3）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C实验32（3）Doc)));
	return (C实验32（3）Doc*)m_pDocument;
}
#endif //_DEBUG


// C实验32（3）View 消息处理程序


void C实验32（3）View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C实验32（3）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s, s1, s2;
	int x = rand() % 100 + 5;


	CClientDC dc(this);
	if (point.x > 40 && point.x < 200 && point.y>40 && point.y < 200)
	{
		pDoc->a = x;
		s.Format(_T("%d"), pDoc->a);
		dc.TextOutW(point.x, point.y, s);
	}
	else if (point.x > 220 && point.x < 400 && point.y>220 && point.y < 400)
	{
		pDoc->b = x;
		s1.Format(_T("%d"), pDoc->b);
		dc.TextOutW(point.x, point.y, s1);

	}
	else if (point.x > 500 && point.x < 720 && point.y>400 && point.y < 600)
	{

		s2.Format(_T("%d"), pDoc->a + pDoc->b);
		dc.TextOutW(point.x, point.y, s2);
	}
	else
	{
		s2 = "点击无效";
		dc.TextOutW(point.x, point.y, s2);
	}
}
