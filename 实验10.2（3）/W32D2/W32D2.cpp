// W32D2.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "W32D2.h"
#include"math.h"


// 这是导出变量的一个示例
W32D2_API int nW32D2=0;

// 这是导出函数的一个示例。
W32D2_API int fnW32D2(void)
{
    return 42;
}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 W32D2.h
CW32D2::CW32D2()
{
    return;
}
float Rad_to_deg = 45.0 / atan(1.0);
W32D2_API float FAC::convert(float deg)
{

	return   deg / Rad_to_deg;
}