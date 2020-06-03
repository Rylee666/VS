// W32D1.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "W32D1.h"


// 这是导出变量的一个示例
W32D1_API int nW32D1=0;

// 这是导出函数的一个示例。
W32D1_API int fnW32D1(void)
{
    return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 W32D1.h
CW32D1::CW32D1()
{
    return;
}
W32D1_API int Factorial(int n) {

	int num = 1;
	if (n <= 0)  return 0;
	if (n >= 17) return -1;
	for (int i = 1; i <= n; i++)
	{
		num *= i;
	}
	return num;
}