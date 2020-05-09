
// 实验5.2（3）View.h : C实验52（3）View 类的接口
//

#pragma once


class C实验52（3）View : public CView
{
protected: // 仅从序列化创建
	C实验52（3）View();
	DECLARE_DYNCREATE(C实验52（3）View)

// 特性
public:
	C实验52（3）Doc* GetDocument() const;

// 操作
public:
	CPoint m_point;
	CPoint n_point;
	CRect m_Crect;
	int set;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C实验52（3）View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnOnline();
	afx_msg void OnOnrectangle();
	afx_msg void OnOnellipse();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 实验5.2（3）View.cpp 中的调试版本
inline C实验52（3）Doc* C实验52（3）View::GetDocument() const
   { return reinterpret_cast<C实验52（3）Doc*>(m_pDocument); }
#endif

