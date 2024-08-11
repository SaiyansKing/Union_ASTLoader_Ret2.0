#include "hook.h"

BOOL WINAPI DllMain(HINSTANCE hInst, DWORD reason, LPVOID)
{
    if(reason == DLL_PROCESS_ATTACH)
    {
        if(DWORD ASTAPI = (DWORD)LoadLibraryA("AST.dll"))
        {
            HookJMP(ASTAPI + 0xCB72A, 0x7B4460);
            HookJMP(ASTAPI + 0xCB724, 0x7B446F);
        }
    }
    return TRUE;
}
