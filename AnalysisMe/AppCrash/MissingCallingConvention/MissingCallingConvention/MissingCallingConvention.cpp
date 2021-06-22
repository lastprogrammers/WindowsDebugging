// CrashMissingCallingConvention.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

typedef int (*pfnCdeclCallback)(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t);

int cdeclCallback(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t)
{
    std::cout << "cdeclCallback called" << std::endl;
    return 0;
}

int __stdcall stdcallCallback(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m, int n, int o, int p, int q, int r, int s, int t)
{
    std::cout << "stdcallCallback called" << std::endl;
    return 0;
}

int main()
{
#ifndef _WIN64
    pfnCdeclCallback pfnCallback1 = reinterpret_cast<pfnCdeclCallback>(stdcallCallback);
    pfnCdeclCallback pfnCallback2 = cdeclCallback;

    pfnCallback1(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
    pfnCallback2(1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
#else
    std::cout << "This platform is not supported" << std::endl;
#endif

    return 0;
}
