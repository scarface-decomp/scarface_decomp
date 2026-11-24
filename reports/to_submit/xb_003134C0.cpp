// bin: xb
// va: 0x003134C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003134C0 (0x003134C0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0041D624;
extern "C" int DAT_00475934;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_003134C0(void)
{
    DAT_00475934 = sub_00244040(DAT_0041D624, 0);
}
