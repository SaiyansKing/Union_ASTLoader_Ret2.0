#pragma once
#include <windows.h>

__declspec(noinline) void HookJMP(DWORD dwAddress, DWORD dwFunction);
