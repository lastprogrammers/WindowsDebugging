#include <iostream>
#include "BasicTracing.h"
#include "AdvancedTracing.h"
#include "Utility.h"
#include "EnumDef.h"

#if defined(_WIN64)
#error Set to x86 mode
#endif

DEBUGGIG_MODE g_Mode;

int main()
{
    int input;
    UtilityInit();

    while(true)
    {
        std::cout << "Choice Mode(1:BasicTracing 2:AdvancedTracing other:Exit)? ";
        std::cin >> input;
        g_Mode = (DEBUGGIG_MODE)input;

        if (g_Mode == DEBUGGIG_MODE::BasicTracing)
        {
            // BreakPoint and StepInto Me!
            BasicTracing();
        }
        else if (g_Mode == DEBUGGIG_MODE::AdvancedTracing)
        {
            // BreakPoint and StepInto Me!
            AdvancedTracing();
        }
        else
        {
            std::cout << "Stop Debugging!\n";
            break;
        }
    }

    return 0;
}
