#if !defined(_WIN64) || !defined(_DEBUG)
#error Set to Debug x64 mode
#endif


#include <iostream>

int SecondStackFrame64(int64_t a, int64_t b)
{
	char c[100] = { 0 };

	// SecondStackFrame64 rsp = current rsp + local&home size(sub rsp,xxxh) + push size(count*8)
	// SecondStackFrame64 rsp = FirstStackFrame64 return address
	printf("BreakPointMe\n");

	return 0;
}

int FirstStackFrame64(int64_t a, int64_t b)
{
	// FirstStackFrame64 rsp = SecondStackFrame64 rsp + "ret" size(8) + local&home size(sub rsp,xxxh) + push size(count*8)
	// FirstStackFrame64 rsp = main return address
	SecondStackFrame64(b, a);
	return 0;
}

int main()
{
	int64_t a = 0x11223344;
	int64_t b = 0x55667788;

	// main rsp = FirstStackFrame64 rsp + ret size(8) + local&home size(sub rsp,xxxh) + push size(count*8)
	FirstStackFrame64(a, b);
}

