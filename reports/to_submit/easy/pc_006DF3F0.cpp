// bin: pc
// va: 0x006DF3F0
// tool: the portal's starter code (no AI)
// sub_006DF3F0 (0x006DF3F0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0072F0EC;
extern "C" int __cdecl sub_006DF3A0(void);

void __cdecl sub_006DF3F0(int a1)
{
    *(int*)(sub_006DF3A0() + 32) = a1;
    ((void (__stdcall*)(int))DAT_0072F0EC)(*(int*)(a1 + 20));
}
