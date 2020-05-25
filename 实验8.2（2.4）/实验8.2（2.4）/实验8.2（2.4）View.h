
// 实验8.2（2.4）View.h : C实验82（24）View 类的接口
//

#pragma once


class C实验82（24）View : public CView
{
protected: // 仅从序列化创建
	C实验82（24）View();
	DECLARE_DYNCREATE(C实验82（24）View)

// 特性
public:
	C实验82（24）Doc* GetDocument() const;

// 操作
public:
	int r, g, b;
	bool flag;
	CRect rect;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C实验82（24）View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopout();
};

#ifndef _DEBUG  // 实验8.2（2.4）View.cpp 中的调试版本
inline C实验82（24）Doc* C实验82（24）View::GetDocument() const
   { return reinterpret_cast<C实验82（24）Doc*>(m_pDocument); }
#endif

