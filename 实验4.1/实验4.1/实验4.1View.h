
// 实验4.1View.h : C实验41View 类的接口
//

#pragma once


class C实验41View : public CView
{
protected: // 仅从序列化创建
	C实验41View();
	DECLARE_DYNCREATE(C实验41View)

// 特性
public:
	C实验41Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C实验41View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 实验4.1View.cpp 中的调试版本
inline C实验41Doc* C实验41View::GetDocument() const
   { return reinterpret_cast<C实验41Doc*>(m_pDocument); }
#endif

