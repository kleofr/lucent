#include "test.h"
#include <stdio.h>

namespace lucent
{
	__declspec(dllexport) void Print()
	{
		printf("LUCENT::STARTED_WORKING");
	}
}