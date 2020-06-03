
// useLibView.cpp : CuseLibView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "useLib.h"
#endif

#include "useLibDoc.h"
#include "useLibView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "w32.h"

// CuseLibView

IMPLEMENT_DYNCREATE(CuseLibView, CView)

BEGIN_MESSAGE_MAP(CuseLibView, CView)
END_MESSAGE_MAP()

// CuseLibView 构造/析构

CuseLibView::CuseLibView()
{
	// TODO: 在此处添加构造代码

}

CuseLibView::~CuseLibView()
{
}

BOOL CuseLibView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CuseLibView 绘制

void CuseLibView::OnDraw(CDC* pDC)
{
	CuseLibDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	float deg = 30.0;
	FAC m_FAC;
	float value = m_FAC.convert(deg);
	CString s;
	s.Format(_T("%f的弧度值为%f"), deg, value);
	pDC->TextOutW(200, 180, s);
	// TODO: 在此处为本机数据添加绘制代码
}


// CuseLibView 诊断

#ifdef _DEBUG
void CuseLibView::AssertValid() const
{
	CView::AssertValid();
}

void CuseLibView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CuseLibDoc* CuseLibView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CuseLibDoc)));
	return (CuseLibDoc*)m_pDocument;
}
#endif //_DEBUG


// CuseLibView 消息处理程序
