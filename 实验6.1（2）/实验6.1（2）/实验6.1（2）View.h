
// ʵ��6.1��2��View.h : Cʵ��61��2��View ��Ľӿ�
//

#pragma once


class Cʵ��61��2��View : public CView
{
protected: // �������л�����
	Cʵ��61��2��View();
	DECLARE_DYNCREATE(Cʵ��61��2��View)

// ����
public:
	Cʵ��61��2��Doc* GetDocument() const;

// ����
public:
	int r, w, h, sx, sy;
	CString filename;
	float rect_radio, image_radio;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cʵ��61��2��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // ʵ��6.1��2��View.cpp �еĵ��԰汾
inline Cʵ��61��2��Doc* Cʵ��61��2��View::GetDocument() const
   { return reinterpret_cast<Cʵ��61��2��Doc*>(m_pDocument); }
#endif

