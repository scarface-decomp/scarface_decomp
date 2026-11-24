// bin: proto
// va: 0x0005E560
// what: 
// tool: the portal's starter code (no AI)

// sub_0005E560 (Proto 0x0005E560, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0043D700[];
extern "C" void __cdecl sub_00058C00(int, int, int);
extern "C" void __cdecl sub_00066320(int);
extern "C" int __cdecl sub_000BBD10(int);

void __cdecl sub_0005E560(int a1, int a2, int a3)
{
    sub_00058C00((int)DAT_0043D700, 256, *(int*)(a3 + 4));
    sub_00066320(sub_000BBD10((int)DAT_0043D700));
}
