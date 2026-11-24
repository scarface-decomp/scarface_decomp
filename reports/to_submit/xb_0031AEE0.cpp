// bin: xb
// va: 0x0031AEE0
// what: Start-up code (a static initializer): stores the name key of "priority" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031AEE0 (0x0031AEE0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C3614[];
extern "C" int DAT_0048E674;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031AEE0(void)
{
    DAT_0048E674 = sub_00244040((int)DAT_003C3614, 0);
}
