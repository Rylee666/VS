// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "实验9.1（2）.h"
#include "MyDlg.h"
#include "afxdialogex.h"

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

// MyDlg 对话框

IMPLEMENT_DYNAMIC(MyDlg, CDialogEx)

MyDlg::MyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MyDlg::~MyDlg()
{
}

void MyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDlg 消息处理程序


void MyDlg::OnBnClickedButton1()
{
	CFileDialog cfd(true);
	CImage img;
	CString s1;
	int t = cfd.DoModal();
	if (t == IDOK)
	{

		CString filename = cfd.GetPathName();
		ifstream ifs(filename);
		string s;
		ifs >> s;
		int sx, sy, w, h;
		s1 = CString(s.c_str());
		img.Load(s1);
		foo(img, sx, sy, w, h);
		CDC* pDC = GetDlgItem(IDC_STATIC)->GetDC();
		img.Draw(pDC->m_hDC, sx, sy, w, h);
		ReleaseDC(pDC);

	}
	// TODO: 在此添加控件通知处理程序代码
}

void MyDlg::foo(CImage& img, int& sx, int& sy, int& w, int& h)
{
	CRect rect;

	GetClientRect(&rect);
	GetDlgItem(IDC_STATIC)->GetClientRect(&rect);
	float rect_radio = 1.0 * rect.Width() / rect.Height();
	float image_radio = 1.0 * img.GetWidth() / img.GetHeight();

	if (rect_radio > image_radio)
	{
		h = rect.Height();
		w = image_radio * h;
		sx = (rect.Width() - w) / 2;
		sy = 0;
	}
	else {
		w = rect.Width();
		h = w / image_radio;
		sx = 0;
		sy = (rect.Height() - h) / 2;
	}
}
