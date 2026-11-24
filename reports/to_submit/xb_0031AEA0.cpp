// bin: xb
// va: 0x0031AEA0
// what: Start-up code (a static initializer): stores the name key of "TOD" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031AEA0 (0x0031AEA0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C35FC[];
extern "C" int DAT_0048E668;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031AEA0(void)
{
    DAT_0048E668 = sub_00244040((int)DAT_003C35FC, 0);
}
