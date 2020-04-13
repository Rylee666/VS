
// 实验1.1View.h : C实验11View 类的接口
//

#pragma once


class C实验11View : public CView
{
protected: // 仅从序列化创建
	C实验11View();
	DECLARE_DYNCREATE(C实验11View)

// 特性
public:
	C实验11Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~C实验11View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 实验1.1View.cpp 中的调试版本
inline C实验11Doc* C实验11View::GetDocument() const
   { return reinterpret_cast<C实验11Doc*>(m_pDocument); }
#endif

