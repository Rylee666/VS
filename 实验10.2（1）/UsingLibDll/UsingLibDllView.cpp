
// UsingLibDllView.cpp : CUsingLibDllView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "UsingLibDll.h"
#endif

#include "UsingLibDllDoc.h"
#include "UsingLibDllView.h"
#include"w32.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUsingLibDllView

IMPLEMENT_DYNCREATE(CUsingLibDllView, CView)

BEGIN_MESSAGE_MAP(CUsingLibDllView, CView)
END_MESSAGE_MAP()

// CUsingLibDllView 构造/析构

CUsingLibDllView::CUsingLibDllView()
{
	// TODO: 在此处添加构造代码

}

CUsingLibDllView::~CUsingLibDllView()
{
}

BOOL CUsingLibDllView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CUsingLibDllView 绘制

void CUsingLibDllView::OnDraw(CDC* pDC)
{
	CUsingLibDllDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	int n = 5;
	int a = Factorial(5);
	if (a == 0)
	{
		pDC->TextOutW(200, 180, _T("n的值必须大于0"));
	}
	if (a == -1)
	{
		pDC->TextOutW(200, 180, _T("n的阶乘结果溢出"));
	}
	if (a != 0 && a != -1)
	{
		s.Format(_T("%d的阶乘为%d"), n, a);
		pDC->TextOutW(200, 100, s);
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// CUsingLibDllView 诊断

#ifdef _DEBUG
void CUsingLibDllView::AssertValid() const
{
	CView::AssertValid();
}

void CUsingLibDllView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUsingLibDllDoc* CUsingLibDllView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUsingLibDllDoc)));
	return (CUsingLibDllDoc*)m_pDocument;
}
#endif //_DEBUG


// CUsingLibDllView 消息处理程序
