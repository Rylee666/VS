
// ʵ��6.1��2��View.cpp : Cʵ��61��2��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ʵ��6.1��2��.h"
#endif

#include "ʵ��6.1��2��Doc.h"
#include "ʵ��6.1��2��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cʵ��61��2��View

IMPLEMENT_DYNCREATE(Cʵ��61��2��View, CView)

BEGIN_MESSAGE_MAP(Cʵ��61��2��View, CView)
	ON_COMMAND(ID_FILE_OPEN, &Cʵ��61��2��View::OnFileOpen)
END_MESSAGE_MAP()

// Cʵ��61��2��View ����/����

Cʵ��61��2��View::Cʵ��61��2��View()
{
	// TODO: �ڴ˴���ӹ������

}

Cʵ��61��2��View::~Cʵ��61��2��View()
{
}

BOOL Cʵ��61��2��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cʵ��61��2��View ����

void Cʵ��61��2��View::OnDraw(CDC* pDC)
{
	Cʵ��61��2��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CRect rect;
	GetClientRect(&rect);

	if (r == IDOK)
	{
		CImage m_image;
		m_image.Load(filename);
		rect_radio = 1.0*rect.Width() / rect.Height();
		image_radio = 1.0 * m_image.GetWidth() / m_image.GetHeight();

		if (rect_radio > image_radio)
		{
			h = rect.Height();
			w = image_radio * h;
			sx = (rect.Width() - w) / 2;
			sy = 0;
		}
		else {
			w = rect.Width();
			h = w / image_radio;
			sx = 0;
			sy = (rect.Height() - h) / 2;
		}
		m_image.Draw(pDC->m_hDC, sx, sy, w, h);
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cʵ��61��2��View ���

#ifdef _DEBUG
void Cʵ��61��2��View::AssertValid() const
{
	CView::AssertValid();
}

void Cʵ��61��2��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cʵ��61��2��Doc* Cʵ��61��2��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cʵ��61��2��Doc)));
	return (Cʵ��61��2��Doc*)m_pDocument;
}
#endif //_DEBUG


// Cʵ��61��2��View ��Ϣ�������


void Cʵ��61��2��View::OnFileOpen()
{
	CFileDialog cfd(true);
	r = cfd.DoModal();
	filename = cfd.GetPathName();
	Invalidate();
	// TODO: �ڴ���������������
}
