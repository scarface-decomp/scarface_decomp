// bin: xb
// va: 0x003190E0
// what: Start-up code (a static initializer): stores the name key of "DefaultAnimSpeed" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003190E0 (0x003190E0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B5CD0[];
extern "C" int DAT_0048BEA8;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_003190E0(void)
{
    DAT_0048BEA8 = sub_00244040((int)DAT_003B5CD0, 0);
}
