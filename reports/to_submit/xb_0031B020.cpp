// bin: xb
// va: 0x0031B020
// what: Start-up code (a static initializer): stores the name key of "none" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B020 (0x0031B020, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A5300[];
extern "C" int DAT_0048E69C;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031B020(void)
{
    DAT_0048E69C = sub_00244040((int)DAT_003A5300, 0);
}
