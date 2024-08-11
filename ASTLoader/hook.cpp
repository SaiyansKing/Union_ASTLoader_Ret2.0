#include "hook.h"

void HookJMP(DWORD dwAddress, DWORD dwFunction)
{
	DWORD dwOldProtect, dwNewProtect, dwNewCall;
	dwNewCall = dwFunction - dwAddress - 5;
	if(VirtualProtect(reinterpret_cast<LPVOID>(dwAddress), 5, PAGE_EXECUTE_READWRITE, &dwOldProtect))
	{
		*reinterpret_cast<BYTE*>(dwAddress) = 0xE9;
		*reinterpret_cast<DWORD*>(dwAddress + 1) = dwNewCall;
		VirtualProtect(reinterpret_cast<LPVOID>(dwAddress), 5, dwOldProtect, &dwNewProtect);
		FlushInstructionCache(GetCurrentProcess(), reinterpret_cast<LPVOID>(dwAddress), 5);
	}
}
