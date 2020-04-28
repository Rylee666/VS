
// 实验3.2（2)View.cpp : C实验32（2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "实验3.2（2).h"
#endif

#include "实验3.2（2)Doc.h"
#include "实验3.2（2)View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C实验32（2View

IMPLEMENT_DYNCREATE(C实验32（2View, CView)

BEGIN_MESSAGE_MAP(C实验32（2View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C实验32（2View 构造/析构

C实验32（2View::C实验32（2View()
{
	// TODO: 在此处添加构造代码

}

C实验32（2View::~C实验32（2View()
{
}

BOOL C实验32（2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C实验32（2View 绘制

void C实验32（2View::OnDraw(CDC* pDC)
{
	C实验32（2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOutW(10, 20, _T("请点击鼠标左键"));
	// TODO: 在此处为本机数据添加绘制代码
}


// C实验32（2View 诊断

#ifdef _DEBUG
void C实验32（2View::AssertValid() const
{
	CView::AssertValid();
}

void C实验32（2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C实验32（2Doc* C实验32（2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C实验32（2Doc)));
	return (C实验32（2Doc*)m_pDocument;
}
#endif //_DEBUG


// C实验32（2View 消息处理程序


void C实验32（2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C实验32（2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	s.Format(_T("a+b=%d"), pDoc->a + pDoc->b);
	CClientDC dc(this);
	dc.TextOutW(200, 200, s);
	CView::OnLButtonDown(nFlags, point);
}
