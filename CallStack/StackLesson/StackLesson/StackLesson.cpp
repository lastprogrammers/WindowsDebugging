#if !defined(_DEBUG)
#error Set to Debug mode
#endif

#include <iostream>

#ifndef _WIN64	// Debug - x86
void NoRetNoParams()
{
	unsigned long ulOldEBP = 0;
	unsigned long ulCurrentEBP = 0;
	unsigned long ulRetIP = 0;

	_asm 
	{
		mov ulCurrentEBP, EBP
	}

	ulOldEBP = *(unsigned long*)ulCurrentEBP;
	ulRetIP = *(unsigned long*)(ulCurrentEBP + 4);

	printf("OldEBP %x, Current EBP %x, Return IP %x \n", ulOldEBP, ulCurrentEBP, ulRetIP);	
	
}

int __cdecl cdeclCallingConventionWithParams(const char* Arg1, unsigned long Arg2)
{
	int nLocalVar1 = Arg2 + 2009;
	int nLocalVar2 = 0;

	_asm
	{
		push eax
		mov eax, [ebp+8]
		mov nLocalVar2, eax
		pop eax
	}
	
	printf("FunctionType: %s \n", nLocalVar2);

	return nLocalVar1;
}

int __stdcall stdcallCallingConventionWithParams(const char* Arg1, unsigned long Arg2)
{
	int nLocalVar = Arg2 + 2010;

	printf("FunctionType: %s \n", Arg1);

	return nLocalVar;
}

int __fastcall fastcallCallingConventionWithParams(const char* Arg1, unsigned long Arg2, unsigned long Arg3)
{
	char*			pLocalVar1;
	unsigned long	ulLocalVar2;
	unsigned long	ulLocalVar3;
	
	_asm
	{
		mov pLocalVar1, ECX
		mov ulLocalVar2, EDX
		push eax
		mov eax, [ebp+8]
		mov ulLocalVar3, eax
		pop eax
	}

	printf("FunctionType: %s \n", pLocalVar1);

	return ulLocalVar3;
}

class CSampleClass
{
public:
	CSampleClass(): nJunk(0) {}
	virtual ~CSampleClass() {}

	int nJunk;
	
	int ShowThisCallCallingConvention(const char* Arg1, unsigned long Arg2, unsigned long Arg3)
	{
		CSampleClass* pThis = NULL;
		_asm mov pThis, ECX
		char* LocalVar1 = NULL;
		unsigned long LocalVar2 = Arg2;
		unsigned long LocalVar3 = Arg3;


		nJunk = Arg2 + Arg3 + 2012;

		if (pThis == this)
		{
			printf("ECX has this pointer! (%x) \n", pThis);
		}

		printf("FunctionType: %s \n", Arg1);
		return nJunk;
	}
};

#else	// Debug - x64

int SecondStackFrame64(int a, int b)
{
	char c[100] = {0};
	printf("SecondStackFrame64 called\n");
	return 0;
}

int FirstStackFrame64(int a, int b)
{
	char c[10] = {0};
	printf("FirstStackFrame64 called\n");
	SecondStackFrame64(a, b);
	return 0;
}
#endif

int main(int argc, char* argv[])
{
#ifndef _WIN64	// Debug - x86
	NoRetNoParams();

	// cdecl calling convention
	cdeclCallingConventionWithParams("cdecl Calling Convention", 'cdec');
	
	// stdcall calling convention
	stdcallCallingConventionWithParams("stdcall Calling Convention", 'stdc');

	// fastcall calling convention
	fastcallCallingConventionWithParams("fastcall Calling Convention", 'fast', 'call');

	// thiscall calling convention
	CSampleClass sample;
	sample.ShowThisCallCallingConvention("thiscall Calling Convention", 'this', 'call');
#else	// Debug - x64
	// 64bit stack-frame
	FirstStackFrame64(1, 2);
#endif

	return 0;
}

