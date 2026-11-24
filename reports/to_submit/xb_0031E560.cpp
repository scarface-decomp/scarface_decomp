// bin: xb
// va: 0x0031E560
// what: Start-up code (a static initializer): stores the name key of "TargetSet" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E560 (0x0031E560, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D858[];
extern "C" int DAT_00490BD4;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031E560(void)
{
    DAT_00490BD4 = sub_00244040((int)DAT_0039D858, 0);
}
