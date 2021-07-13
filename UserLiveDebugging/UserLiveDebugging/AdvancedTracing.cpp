#include <iostream>
#include <cstdlib>
#include <Windows.h>

int g_Key;

int ExceptionFunction(int* pValue)
{
	int value = *pValue;

	for (int i = 0; i < 10000000; i++)
	{
		value = value & 0xFFFF;
		value = value << 1;
		value = value & (value & 0xFFFF);
		value = value >> 1;
		value = value & 0xFFFFFF;
		value = value << 1;
		value = value & (value & 0xFFFFFF);
		value = value >> 1;
	}

	value = value / *pValue;
	value = value + rand();

	return value;
}

int NormalValueCheck()
{
	int value = rand();	
	g_Key = value % 2 == 0 ? value & 0xFF : 0;

	if (g_Key != 0)
	{
		std::cout << "Key: " << g_Key << std::endl;
		value = ExceptionFunction(&g_Key);
	}

	return value;
}

void AdvancedTracing()
{
	std::cout << "AdvancedTracing - Trace me in WinDbg!\n";

	for (int i = 0; i < 1000; i++)
	{
		NormalValueCheck();
	}
}