
// ʵ��6.2��1��View.h : Cʵ��62��1��View ��Ľӿ�
//

#pragma once


class Cʵ��62��1��View : public CView
{
protected: // �������л�����
	Cʵ��62��1��View();
	DECLARE_DYNCREATE(Cʵ��62��1��View)

// ����
public:
	Cʵ��62��1��Doc* GetDocument() const;

// ����
public:
	CString s;
	CPoint p;
	CRect r;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cʵ��62��1��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // ʵ��6.2��1��View.cpp �еĵ��԰汾
inline Cʵ��62��1��Doc* Cʵ��62��1��View::GetDocument() const
   { return reinterpret_cast<Cʵ��62��1��Doc*>(m_pDocument); }
#endif

