
// useLibView.h : CuseLibView 类的接口
//

#pragma once


class CuseLibView : public CView
{
protected: // 仅从序列化创建
	CuseLibView();
	DECLARE_DYNCREATE(CuseLibView)

// 特性
public:
	CuseLibDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CuseLibView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // useLibView.cpp 中的调试版本
inline CuseLibDoc* CuseLibView::GetDocument() const
   { return reinterpret_cast<CuseLibDoc*>(m_pDocument); }
#endif

