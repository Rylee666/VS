
// 实验5.2（3）View.cpp : C实验52（3）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "实验5.2（3）.h"
#endif

#include "实验5.2（3）Doc.h"
#include "实验5.2（3）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C实验52（3）View

IMPLEMENT_DYNCREATE(C实验52（3）View, CView)

BEGIN_MESSAGE_MAP(C实验52（3）View, CView)
	ON_COMMAND(ID_ONLINE, &C实验52（3）View::OnOnline)
	ON_COMMAND(ID_OnRectangle, &C实验52（3）View::OnOnrectangle)
	ON_COMMAND(ID_OnEllipse, &C实验52（3）View::OnOnellipse)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C实验52（3）View 构造/析构

C实验52（3）View::C实验52（3）View()
{
	// TODO: 在此处添加构造代码

}

C实验52（3）View::~C实验52（3）View()
{
}

BOOL C实验52（3）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C实验52（3）View 绘制

void C实验52（3）View::OnDraw(CDC* pDC)
{
	C实验52（3）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C实验52（3）View 诊断

#ifdef _DEBUG
void C实验52（3）View::AssertValid() const
{
	CView::AssertValid();
}

void C实验52（3）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C实验52（3）Doc* C实验52（3）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C实验52（3）Doc)));
	return (C实验52（3）Doc*)m_pDocument;
}
#endif //_DEBUG


// C实验52（3）View 消息处理程序


void C实验52（3）View::OnOnline()
{
	CClientDC dc(this);
	// TODO: 在此添加命令处理程序代码
	set = 1;
	CPen pen(PS_SOLID, 5, RGB(0, 0, 0));
	CPen* oldPen = dc.SelectObject(&pen);
}


void C实验52（3）View::OnOnrectangle()
{
	CClientDC dc(this);
	set = 2;
	GetClientRect(&m_Crect);
	// TODO: 在此添加命令处理程序代码
}


void C实验52（3）View::OnOnellipse()
{
	set = 3;
	// TODO: 在此添加命令处理程序代码
}


void C实验52（3）View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_point.x = point.x;
	m_point.y = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void C实验52（3）View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CClientDC dc(this);
	CView::OnLButtonUp(nFlags, point);
	n_point.x = point.x;
	n_point.y = point.y;
	switch (set)
	{
	case 1:
		dc.MoveTo(n_point.x, n_point.y);
		dc.LineTo(m_point.x, m_point.y);
		break;
	case 2:
		m_Crect.left = m_point.x;
		m_Crect.top = m_point.y;
		m_Crect.right = n_point.x;
		m_Crect.bottom = n_point.y;
		dc.Rectangle(m_Crect);
		break;
	case 3:
		m_Crect.left = m_point.x;
		m_Crect.top = m_point.y;
		m_Crect.right = n_point.x;
		m_Crect.bottom = n_point.y;
		dc.Ellipse(m_Crect);
		break;
	default:
		break;
	}
}
