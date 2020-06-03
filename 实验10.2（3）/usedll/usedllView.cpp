
// usedllView.cpp : CusedllView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "usedll.h"
#endif

#include "usedllDoc.h"
#include "usedllView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#include"W32D1.h"
#include"W32D2.h"
// CusedllView

IMPLEMENT_DYNCREATE(CusedllView, CView)

BEGIN_MESSAGE_MAP(CusedllView, CView)
END_MESSAGE_MAP()

// CusedllView 构造/析构

CusedllView::CusedllView()
{
	// TODO: 在此处添加构造代码

}

CusedllView::~CusedllView()
{
}

BOOL CusedllView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CusedllView 绘制

void CusedllView::OnDraw(CDC* pDC)
{
	CusedllDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s, s1;
	float deg = 30.0;
	FAC m_FAC;
	int n = 5;
	int a = Factorial(n);
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


	float value = m_FAC.convert(deg);
	s1.Format(_T("%f的弧度值为%f"), deg, value);
	pDC->TextOutW(200, 300, s1);

	// TODO: 在此处为本机数据添加绘制代码
}


// CusedllView 诊断

#ifdef _DEBUG
void CusedllView::AssertValid() const
{
	CView::AssertValid();
}

void CusedllView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CusedllDoc* CusedllView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CusedllDoc)));
	return (CusedllDoc*)m_pDocument;
}
#endif //_DEBUG


// CusedllView 消息处理程序
