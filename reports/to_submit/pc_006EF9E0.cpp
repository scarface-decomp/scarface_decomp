// bin: pc
// va: 0x006EF9E0
// what: 
// tool: the portal's starter code (no AI)

// sub_006EF9E0 (PC 0x006EF9E0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0085D134;
extern "C" void __cdecl sub_006F4A80(int, int);

bool __cdecl sub_006EF9E0(int a1)
{
    sub_006F4A80(DAT_0085D134, a1);
    *(int*)(a1 + 32) = 0;
    *(int*)(a1 + 28) = 0;
    *(bool*)(a1 + 24) = false;
    return true;
}
