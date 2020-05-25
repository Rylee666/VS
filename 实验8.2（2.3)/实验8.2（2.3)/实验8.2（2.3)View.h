
// 实验8.2（2.3)View.h : C实验82（23View 类的接口
//

#pragma once


class C实验82（23View : public CView
{
protected: // 仅从序列化创建
	C实验82（23View();
	DECLARE_DYNCREATE(C实验82（23View)

// 特性
public:
	C实验82（23Doc* GetDocument() const;

// 操作
public:
	CRect rect,rect1;
	CPoint point;
	int x1, x2, y1, y2, flag;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C实验82（23View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 实验8.2（2.3)View.cpp 中的调试版本
inline C实验82（23Doc* C实验82（23View::GetDocument() const
   { return reinterpret_cast<C实验82（23Doc*>(m_pDocument); }
#endif

