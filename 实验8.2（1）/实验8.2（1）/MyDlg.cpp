// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "实验8.2（1）.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x(0)
	, y(0)
	, r(0)
	, q(_T(""))
	, a(0)
	, b(_T(""))
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x);
	DDX_Text(pDX, IDC_EDIT2, y);
	DDX_Text(pDX, IDC_EDIT3, r);
	DDX_Text(pDX, IDC_EDIT4, q);
	DDX_Text(pDX, IDC_EDIT5, a);
	DDX_Text(pDX, IDC_EDIT6, b);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MyDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &MyDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &MyDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &MyDlg::OnBnClickedButton5)
	ON_EN_CHANGE(IDC_EDIT1, &MyDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON8, &MyDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// MyDlg 消息处理程序


void MyDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	r = x + y;
	UpdateData(false);
}


void MyDlg::OnBnClickedButton2()
{
	this->UpdateData(true);
	r = x -y;
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void MyDlg::OnBnClickedButton3()
{
	this->UpdateData(true);
	r = x *y;
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void MyDlg::OnBnClickedButton4()
{
	CString s = _T("除数不可为0");
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);

	if (y == 0)
	{
		q = s;
	}
	else
	{
		r = (double)x / y;
	}
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void MyDlg::OnBnClickedButton5()
{
	CString s = _T("平方内不可为负数");
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if (x <0 || y < 0)
	{
		q = s;
		b = s;
	}
	else
	{
		r = sqrt(x);
		a = sqrt(y);
	}
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void MyDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void MyDlg::OnBnClickedButton8()
{
	UpdateData(true);
	if (x == 0|| y == 0)
	{
		q= "请输入非零整数";
		b = "请输入非零整数";
	}

	else
	{
		q.Format(_T("1/%d"), x);
		b.Format(_T("1/%d"), y);
	}
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}
