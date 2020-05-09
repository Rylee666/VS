
// 实验6.1（1）View.cpp : C实验61（1）View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "实验6.1（1）.h"
#endif

#include "实验6.1（1）Doc.h"
#include "实验6.1（1）View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C实验61（1）View

IMPLEMENT_DYNCREATE(C实验61（1）View, CView)

BEGIN_MESSAGE_MAP(C实验61（1）View, CView)
	ON_COMMAND(ID_FILE_OPEN, &C实验61（1）View::OnFileOpen)
END_MESSAGE_MAP()

// C实验61（1）View 构造/析构

C实验61（1）View::C实验61（1）View()
{
	// TODO: 在此处添加构造代码

}

C实验61（1）View::~C实验61（1）View()
{
}

BOOL C实验61（1）View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C实验61（1）View 绘制

void C实验61（1）View::OnDraw(CDC* pDC)
{
	C实验61（1）Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rect;
	GetClientRect(&rect);

	if (r == IDOK)
	{
		CImage m_image;
		m_image.Load(filename);
		sx = (rect.Width() - m_image.GetWidth()) / 2;
		sy = (rect.Height() - m_image.GetHeight()) / 2;
		m_image.Draw(pDC->m_hDC, sx, sy, m_image.GetWidth(), m_image.GetHeight());
	}
	// TODO: 在此处为本机数据添加绘制代码
}


// C实验61（1）View 诊断

#ifdef _DEBUG
void C实验61（1）View::AssertValid() const
{
	CView::AssertValid();
}

void C实验61（1）View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C实验61（1）Doc* C实验61（1）View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C实验61（1）Doc)));
	return (C实验61（1）Doc*)m_pDocument;
}
#endif //_DEBUG


// C实验61（1）View 消息处理程序


void C实验61（1）View::OnFileOpen()
{
	CFileDialog cfd(true);
	r = cfd.DoModal();
	filename = cfd.GetPathName();
	Invalidate();
	// TODO: 在此添加命令处理程序代码
}
