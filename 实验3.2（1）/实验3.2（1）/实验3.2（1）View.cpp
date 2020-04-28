
// 实验3.2（1）View.cpp : C实验32（1）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "实验3.2（1）.h"
#endif

#include "实验3.2（1）Doc.h"
#include "实验3.2（1）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C实验32（1）View

IMPLEMENT_DYNCREATE(C实验32（1）View, CView)

BEGIN_MESSAGE_MAP(C实验32（1）View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C实验32（1）View 构造/析构

C实验32（1）View::C实验32（1）View()
{
	// TODO: 在此处添加构造代码

}

C实验32（1）View::~C实验32（1）View()
{
}

BOOL C实验32（1）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C实验32（1）View 绘制

void C实验32（1）View::OnDraw(CDC* /*pDC*/)
{
	C实验32（1）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C实验32（1）View 诊断

#ifdef _DEBUG
void C实验32（1）View::AssertValid() const
{
	CView::AssertValid();
}

void C实验32（1）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C实验32（1）Doc* C实验32（1）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C实验32（1）Doc)));
	return (C实验32（1）Doc*)m_pDocument;
}
#endif //_DEBUG


// C实验32（1）View 消息处理程序


void C实验32（1）View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString s = _T("左键正被按下");
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonDown(nFlags, point);
}


void C实验32（1）View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString c=_T("左键正被抬起");
	CClientDC dc(this);
	dc.TextOutW(200, 200, c);
	CView::OnLButtonUp(nFlags, point);
}
