#include <iostream>

void _fastcall SkipMe(int a, int b)
{
    std::cout << "SkipMe\n";
}

void BreakPointAndGoMe(int a, int b)
{
    std::cout << "BreakPointAndGoMe\n";
}

void StepOverMe(int a, int b)
{
    std::cout << "StepOverMe\n";
}

void StepOutHere()
{
    std::cout << "StepOutHere\n";
}

void _stdcall StepIntoMe(int a, int b)
{
    std::cout << "StepIntoMe\n";

    // Shift + F11
    StepOutHere();

    std::cout << "Don't trace here\n";
}

void RunToCursorHere()
{
    std::cout << "RunToCursorHere\n";
}

void BasicTracing()
{
    std::cout << "BasicTracing - Trace me in WinDbg!\n";

    SkipMe(1, 2);
    SkipMe(1, 2);
    SkipMe(1, 2);
    SkipMe(1, 2);
    SkipMe(1, 2);

    // F9 and F5
    BreakPointAndGoMe(1, 2);

    // F10
    StepOverMe(1, 2);

    // F10
    StepOverMe(1, 2);

    // F10
    StepOverMe(1, 2);

    // F11
    StepIntoMe(1, 2);

    SkipMe(1, 2);
    SkipMe(1, 2);
    SkipMe(1, 2);
    SkipMe(1, 2);
    SkipMe(1, 2);

    // Click and F7
    RunToCursorHere();
}
