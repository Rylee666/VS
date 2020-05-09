
// 实验5.1（1）View.h : C实验51（1）View 类的接口
//

#pragma once


class C实验51（1）View : public CView
{
protected: // 仅从序列化创建
	C实验51（1）View();
	DECLARE_DYNCREATE(C实验51（1）View)

// 特性
public:
	C实验51（1）Doc* GetDocument() const;

// 操作
public:
	int N;
	CArray<CRect, CRect> ca;
	bool set;
	CRect m_window;
	CRect cr;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:

	virtual ~C实验51（1）View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCircles();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 实验5.1（1）View.cpp 中的调试版本
inline C实验51（1）Doc* C实验51（1）View::GetDocument() const
   { return reinterpret_cast<C实验51（1）Doc*>(m_pDocument); }
#endif

