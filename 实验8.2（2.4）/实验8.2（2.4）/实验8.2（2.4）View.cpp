
// 实验8.2（2.4）View.cpp : C实验82（24）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "实验8.2（2.4）.h"
#endif

#include "实验8.2（2.4）Doc.h"
#include "实验8.2（2.4）View.h"
#include "MyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C实验82（24）View

IMPLEMENT_DYNCREATE(C实验82（24）View, CView)

BEGIN_MESSAGE_MAP(C实验82（24）View, CView)
	ON_COMMAND(ID_POPOUT, &C实验82（24）View::OnPopout)
END_MESSAGE_MAP()

// C实验82（24）View 构造/析构

C实验82（24）View::C实验82（24）View()
{
	// TODO: 在此处添加构造代码
	rect.SetRect(50, 100, 200, 300);
	flag = false;
}

C实验82（24）View::~C实验82（24）View()
{
}

BOOL C实验82（24）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C实验82（24）View 绘制

void C实验82（24）View::OnDraw(CDC* pDC)
{
	C实验82（24）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	MyDlg dlg;
	pDC->Ellipse(rect);
	if (flag)
	{
		CBrush newBrush(RGB(r, g, b));
		CBrush* oldBrush = pDC->SelectObject(&newBrush);
		pDC->Ellipse(rect);
		pDC->SelectObject(oldBrush);

	}
	// TODO: 在此处为本机数据添加绘制代码
}


// C实验82（24）View 诊断

#ifdef _DEBUG
void C实验82（24）View::AssertValid() const
{
	CView::AssertValid();
}

void C实验82（24）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C实验82（24）Doc* C实验82（24）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C实验82（24）Doc)));
	return (C实验82（24）Doc*)m_pDocument;
}
#endif //_DEBUG


// C实验82（24）View 消息处理程序


void C实验82（24）View::OnPopout()
{
	MyDlg dlg;
	CClientDC dc(this);
	int t = dlg.DoModal();
	if (t == IDOK)
	{
		r = dlg.x;
		g = dlg.y;
		b = dlg.z;
		flag = true;
		Invalidate();
	}
	// TODO: 在此添加命令处理程序代码
}
