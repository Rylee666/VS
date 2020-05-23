
// 实验8.1View.h : C实验81View 类的接口
//

#pragma once


class C实验81View : public CView
{
protected: // 仅从序列化创建
	C实验81View();
	DECLARE_DYNCREATE(C实验81View)

// 特性
public:
	C实验81Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C实验81View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnPopout();
};

#ifndef _DEBUG  // 实验8.1View.cpp 中的调试版本
inline C实验81Doc* C实验81View::GetDocument() const
   { return reinterpret_cast<C实验81Doc*>(m_pDocument); }
#endif

