#include"stdafx.h"
#include"w32.h"

int Factorial(int n) {
	int num = 1;
	if (n <= 0)  return 0;
	if (n >= 17) return -1;
	for (int i = 1; i <= n; i++)
	{
		num *= i;
	}
	return num;
}