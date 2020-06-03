
// usedllView.h : CusedllView 类的接口
//

#pragma once


class CusedllView : public CView
{
protected: // 仅从序列化创建
	CusedllView();
	DECLARE_DYNCREATE(CusedllView)

// 特性
public:
	CusedllDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CusedllView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // usedllView.cpp 中的调试版本
inline CusedllDoc* CusedllView::GetDocument() const
   { return reinterpret_cast<CusedllDoc*>(m_pDocument); }
#endif

