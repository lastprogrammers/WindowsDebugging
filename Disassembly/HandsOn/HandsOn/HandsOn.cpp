#if defined(_WIN64) || !defined(_DEBUG)
#error Set to Debug x86 mode
#endif

#include <iostream>

void ConditionalStatement()
{
    int x = 5;

    __asm {
        // if (x == 5)
        cmp x, 5;
        je case_equal;
        jmp case_end;

case_equal:
        mov x, 10;
        // if (x > 5)
        cmp x, 5;
        ja case_above;
        jmp case_end;

case_above:
        mov x, 1;
        // if (x < 5)
        cmp x, 5;
        jb case_below;
        jmp case_end;

case_below:
        mov x, 0;
    }

case_end:
    std::cout << x << std::endl;
}


int main()
{
    int x;

    x = 0;
    x++;
    ++x;
    _InterlockedIncrement((long*)&x);
    _InterlockedDecrement((long*)&x);

    printf("Hello World!\n");

    ConditionalStatement();

    return 0;
}

