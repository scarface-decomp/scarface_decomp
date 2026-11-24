// bin: xb
// va: 0x0031F740
// what: Start-up code (a static initializer): stores the name key of "CopsInPursuitSet" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F740 (0x0031F740, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D1A88[];
extern "C" int DAT_00491E74;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031F740(void)
{
    DAT_00491E74 = sub_00244040((int)DAT_003D1A88, 0);
}
