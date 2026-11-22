// bin: pc
// va: 0x006FCFE0
// what: 
// tool: the portal's starter code (no AI)

// sub_006FCFE0 (PC 0x006FCFE0, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F094;
extern "C" int DAT_0072F098;
extern "C" void __cdecl sub_006FC320(int, int, int);

void __cdecl sub_006FCFE0(int a1, int a2)
{
    ((void (__stdcall*)(int))DAT_0072F094)(a1 + 0x290448);
    sub_006FC320(a1, a2, 0);
    ((void (__stdcall*)(int))DAT_0072F098)(a1 + 0x290448);
}
