#include"stdafx.h"
#include"math.h"
#include"w32.h"
float Rad_to_deg = 45.0 / atan(1.0);
float FAC::convert(float deg)
{

	return   deg / Rad_to_deg;
}