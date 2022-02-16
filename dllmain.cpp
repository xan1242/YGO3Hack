#include "stdafx.h"
#include "stdio.h"
#include <windows.h>
#include "includes\injector\injector.hpp"
#include "includes\IniReader.h"
#include "YGO3_MenuIDs.h"

long int MainBase = 0;
int ConfigMenuID = 0;

//int(__stdcall *ScaleFormFunc1)(unsigned int unk1, char* string) = (int(__stdcall*)(unsigned int, char*))0x0109FCC0;
//int(__thiscall *ScaleFormFunc2)(unsigned int dis, char* str, unsigned int unk1, unsigned int unk2) = (int(__thiscall*)(unsigned int , char*, unsigned int, unsigned int))0x116F660;

/*int __stdcall SprintfHook(char* Buffer, const char* Format, ...)
{
	va_list ArgList;
	int Result = 0;
	__crt_va_start(ArgList, Format);
	vfprintf(stdout, Format, ArgList);
	Result = vsprintf(Buffer, Format, ArgList);
	__crt_va_end(ArgList);
	return Result;
}

void __declspec(naked) WaitCave()
{
	getchar();
}*/

//int __stdcall ScaleFormHook1(unsigned int unk1, char* string)
//{
//	printf("ScaleForm Hook1: %s\n", string);
//	return ScaleFormFunc1(unk1, string);
//}
//
//int __stdcall ScaleFormHook2(char* str, unsigned int unk1, unsigned int unk2)
//{
//	unsigned int thethis = 0;
//	_asm mov thethis, ecx
//	printf("ScaleForm Hook2: %s\n", str);
//	return ScaleFormFunc2(thethis, str, unk1, unk2);
//}

//int Init()
//{
//	//injector::WriteMemory<int>(0xFB20C3, (int)&printf, true);
//	//injector::MakeJMP(0x004020C0 + MainBase, printf, true);
//	injector::MakeJMP(0x012867D6, printf, true);
//	injector::MakeCALL(0x010B85DD, SprintfHook, true);
//	//injector::WriteMemory<int>(0x013085C4, (int)&printf, true);
//
//	// force the game to boot
//	//injector::MakeJMP(0x01063A71, 0x1063B64, true);
//	injector::MakeJMP(0x01063A81, 0x1063B64, true);
//
//	injector::MakeCALL(0x0116C855, ScaleFormHook2, true);
//
//	injector::MakeCALL(0x101D8A0 + 0x1F0, ScaleFormHook1, true);
//	injector::MakeCALL(0x101D8A0 + 0x259, ScaleFormHook1, true);
//	injector::MakeCALL(0x101D8A0 + 0x2C3, ScaleFormHook1, true);
//	injector::MakeCALL(0x1049750 + 0x118, ScaleFormHook1, true);
//	injector::MakeCALL(0x105C0E0 + 0x8E, ScaleFormHook1, true);
//	injector::MakeCALL(0x105C6B0 + 0x1BA, ScaleFormHook1, true);
//	injector::MakeCALL(0x1060110 + 0x1AD, ScaleFormHook1, true);
//	injector::MakeCALL(0x1060110 + 0x1DB, ScaleFormHook1, true);
//	injector::MakeCALL(0x1060110 + 0x209, ScaleFormHook1, true);
//	injector::MakeCALL(0x1060110 + 0x237, ScaleFormHook1, true);
//	injector::MakeCALL(0x1060110 + 0x265, ScaleFormHook1, true);
//	injector::MakeCALL(0x1065C90 + 0x1AE, ScaleFormHook1, true);
//	injector::MakeCALL(0x1065C90 + 0x1E7, ScaleFormHook1, true);
//	injector::MakeCALL(0x1065C90 + 0x220, ScaleFormHook1, true);
//	injector::MakeCALL(0x106A3C0 + 0x102, ScaleFormHook1, true);
//	injector::MakeCALL(0x106A3C0 + 0x13B, ScaleFormHook1, true);
//	injector::MakeCALL(0x107B570 + 0x360, ScaleFormHook1, true);
//	injector::MakeCALL(0x107B570 + 0x391, ScaleFormHook1, true);
//	injector::MakeCALL(0x107B570 + 0x3C2, ScaleFormHook1, true);
//	injector::MakeCALL(0x107BD70 + 0x386, ScaleFormHook1, true);
//	injector::MakeCALL(0x107E560 + 0xB6, ScaleFormHook1, true);
//	injector::MakeCALL(0x10834C0 + 0x232, ScaleFormHook1, true);
//	injector::MakeCALL(0x10834C0 + 0x260, ScaleFormHook1, true);
//	injector::MakeCALL(0x10834C0 + 0x28E, ScaleFormHook1, true);
//	injector::MakeCALL(0x10834C0 + 0x2BC, ScaleFormHook1, true);
//	injector::MakeCALL(0x10B1070 + 0x94, ScaleFormHook1, true);
//	injector::MakeCALL(0x10B4E00 + 0x1D9, ScaleFormHook1, true);
//	injector::MakeCALL(0x10B61C0 + 0x117, ScaleFormHook1, true);
//	injector::MakeCALL(0x10B61C0 + 0x158, ScaleFormHook1, true);
//	injector::MakeCALL(0x10B6FA0 + 0xAF, ScaleFormHook1, true);
//	injector::MakeCALL(0x10B7750 + 0xAC, ScaleFormHook1, true);
//	injector::MakeCALL(0x10B7D10 + 0x98, ScaleFormHook1, true);
//	injector::MakeCALL(0x10B8050 + 0xA1, ScaleFormHook1, true);
//	injector::MakeCALL(0x10B8820 + 0x95, ScaleFormHook1, true);
//	injector::MakeCALL(0x10C2430 + 0xE8, ScaleFormHook1, true);
//	injector::MakeCALL(0x10C2430 + 0x20B, ScaleFormHook1, true);
//	injector::MakeCALL(0x10C2750 + 0x85, ScaleFormHook1, true);
//	injector::MakeCALL(0x10C28B0 + 0xD7, ScaleFormHook1, true);
//	injector::MakeCALL(0x10C3370 + 0x627, ScaleFormHook1, true);
//	injector::MakeCALL(0x10C3370 + 0x6AC, ScaleFormHook1, true);
//	injector::MakeCALL(0x10C6930 + 0xDC, ScaleFormHook1, true);
//	injector::MakeCALL(0x10C6930 + 0x16B, ScaleFormHook1, true);
//	injector::MakeCALL(0x10C6930 + 0x1A7, ScaleFormHook1, true);
//	injector::MakeCALL(0x10C7C80 + 0x16B, ScaleFormHook1, true);
//	injector::MakeCALL(0x10C7C80 + 0x1C6, ScaleFormHook1, true);
//
//	return 0;
//}

void NullFunc()
{
	return;
}

int InitConfig()
{
	CIniReader inireader("");
	ConfigMenuID = YGO3_MENUID_MOUSECURSOR + inireader.ReadInteger("YGO3Menu", "MenuID", 18);

	return 0;
}

int Init()
{
	InitConfig();

	//injector::MakeJMP(MainBase + 0x004B3A81, MainBase + 0x4B3B64, true);
	//injector::WriteMemory<unsigned char>(MainBase + 0x4B3A71, 0xCC, true);
	//injector::MakeJMP(MainBase + 0x4B3A71, WaitCave, true);
	injector::WriteMemory<unsigned int>(MainBase + 0x4B4804, MainBase + 0x004B3A81, true);

	// reroute login, go straight to main
	injector::WriteMemory<int>(MainBase + 0x004CA3C9, ConfigMenuID, true);
	injector::WriteMemory<int>(MainBase + 0x4CA3EF, ConfigMenuID, true);

	// hack main menu to not check for net connection, also break callback to data functions
	injector::MakeJMP(MainBase + 0x0046DE1A, MainBase + 0x46DE2E, true);
	injector::WriteMemory<int>(MainBase + 0x0046DE4E, (int)&NullFunc, true);

	//injector::MakeNOP()


	return 0;
}


BOOL APIENTRY DllMain(HMODULE /*hModule*/, DWORD reason, LPVOID /*lpReserved*/)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		uintptr_t base = (uintptr_t)GetModuleHandleA("program.exe");
		AttachConsole(ATTACH_PARENT_PROCESS);
		AllocConsole();
		freopen("CON", "w", stdout);
		freopen("CON", "w", stderr);
		//MainBase = base;
		MainBase = base - 0x400000;
		printf("Base: %X\nMain Base: %X\n", base, MainBase);
		printf("addr1: %x\n", MainBase + 0x004B3A7B);

		Init();
	}
	return TRUE;
}

