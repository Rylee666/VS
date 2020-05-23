
// 实验8.1View.cpp : C实验81View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "实验8.1.h"
#endif

#include "实验8.1Doc.h"
#include "实验8.1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "MyDlg.h"

// C实验81View

IMPLEMENT_DYNCREATE(C实验81View, CView)

BEGIN_MESSAGE_MAP(C实验81View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_POPOUT, &C实验81View::OnPopout)
END_MESSAGE_MAP()

// C实验81View 构造/析构

C实验81View::C实验81View()
{
	// TODO: 在此处添加构造代码

}

C实验81View::~C实验81View()
{
}

BOOL C实验81View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C实验81View 绘制

void C实验81View::OnDraw(CDC* /*pDC*/)
{
	C实验81Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C实验81View 诊断

#ifdef _DEBUG
void C实验81View::AssertValid() const
{
	CView::AssertValid();
}

void C实验81View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C实验81Doc* C实验81View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C实验81Doc)));
	return (C实验81Doc*)m_pDocument;
}
#endif //_DEBUG


// C实验81View 消息处理程序


void C实验81View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	MyDlg md2;
	int r = md2.DoModal();
	if (r == IDOK)
	{
		CString s1 = md2.s;
		GetDC()->TextOutW(200, 100, s1);
	}
	CView::OnLButtonDblClk(nFlags, point);
}


void C实验81View::OnPopout()
{
	// TODO: 在此添加命令处理程序代码
	MyDlg dlg;
	int t = dlg.DoModal();
	if (t == IDOK)
	{

	}
}
