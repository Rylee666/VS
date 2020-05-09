
// 实验5.1（1）View.cpp : C实验51（1）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "实验5.1（1）.h"
#endif

#include "实验5.1（1）Doc.h"
#include "实验5.1（1）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C实验51（1）View

IMPLEMENT_DYNCREATE(C实验51（1）View, CView)

BEGIN_MESSAGE_MAP(C实验51（1）View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// C实验51（1）View 构造/析构

C实验51（1）View::C实验51（1）View()
{
	// TODO: 在此处添加构造代码
	N = 5;
	set = true;
}

C实验51（1）View::~C实验51（1）View()
{
}

BOOL C实验51（1）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C实验51（1）View 绘制

void C实验51（1）View::OnDraw(CDC* /*pDC*/)
{
	C实验51（1）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C实验51（1）View 诊断

#ifdef _DEBUG
void C实验51（1）View::AssertValid() const
{
	CView::AssertValid();
}

void C实验51（1）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C实验51（1）Doc* C实验51（1）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C实验51（1）Doc)));
	return (C实验51（1）Doc*)m_pDocument;
}
#endif //_DEBUG


// C实验51（1）View 消息处理程序

void C实验51（1）View::OnCircles()
{
	GetClientRect(&m_window);
	// TODO: 在此添加命令处理程序代码
	int x1 = (m_window.left + m_window.right) / 2;
	int x2 = (m_window.bottom + m_window.top) / 2;
	GetClientRect(&cr);
	CClientDC DC(this);
	cr.left = x1 - 50;
	cr.right = x1 + 50;
	cr.top = x2 - 50;
	cr.bottom = x2 + 50;

	if (set)
	{
		for (int i = 0; i < N; i++)
		{

			SetTimer(i, 200, NULL);
		}
		set = false;
	}

}
void C实验51（1）View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CView::OnTimer(nIDEvent);
	CView::OnTimer(nIDEvent);
	CClientDC dc(this);
	int i = nIDEvent;
	cr.left -= 5;
	cr.right += 5;
	cr.top -= 5;
	cr.bottom += 5;

	dc.Ellipse(cr);
	CPen pen(PS_SOLID, 20, RGB(rand() % 150, rand() % 150, rand() % 150));
	CPen* color;
	color = dc.SelectObject(&pen);
	dc.Ellipse(cr);
}
