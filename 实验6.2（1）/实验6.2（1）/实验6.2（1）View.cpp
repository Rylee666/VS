
// ʵ��6.2��1��View.cpp : Cʵ��62��1��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ʵ��6.2��1��.h"
#endif

#include "ʵ��6.2��1��Doc.h"
#include "ʵ��6.2��1��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cʵ��62��1��View

IMPLEMENT_DYNCREATE(Cʵ��62��1��View, CView)

BEGIN_MESSAGE_MAP(Cʵ��62��1��View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// Cʵ��62��1��View ����/����

Cʵ��62��1��View::Cʵ��62��1��View()
{
	// TODO: �ڴ˴���ӹ������
	s = "";
	r.left = 20; r.right = 290;
	r.top = 20; r.bottom = 60;
	p.x = 30; p.y = 30;
}

Cʵ��62��1��View::~Cʵ��62��1��View()
{
}

BOOL Cʵ��62��1��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cʵ��62��1��View ����

void Cʵ��62��1��View::OnDraw(CDC* pDC)
{
	Cʵ��62��1��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(r);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cʵ��62��1��View ���

#ifdef _DEBUG
void Cʵ��62��1��View::AssertValid() const
{
	CView::AssertValid();
}

void Cʵ��62��1��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cʵ��62��1��Doc* Cʵ��62��1��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cʵ��62��1��Doc)));
	return (Cʵ��62��1��Doc*)m_pDocument;
}
#endif //_DEBUG


// Cʵ��62��1��View ��Ϣ�������





void Cʵ��62��1��View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	TEXTMETRIC t;
	dc.GetTextMetrics(&t);
	CSize sz = dc.GetTextExtent(s);
	CPoint pt;
	pt.x = p.x + sz.cx;
	pt.y = p.y + sz.cy;
	SetCaretPos(pt);
	if (pt.x<r.right - 15)
		if (0x08 == nChar)//�˸����ɾ������
		{
			COLORREF clr = dc.SetTextColor(dc.GetBkColor());
			dc.TextOutW(p.x, p.y, s);
			s = s.Left(s.GetLength() - 1);
			dc.SetTextColor(clr);
		}
		else
		{
			s += (TCHAR)nChar;
		}
	dc.TextOutW(p.x, p.y, s);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
