// bin: xb
// va: 0x0031F700
// what: Start-up code (a static initializer): stores the name key of "CopFastTalkersSet" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F700 (0x0031F700, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D1A74[];
extern "C" int DAT_00491E64;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031F700(void)
{
    DAT_00491E64 = sub_00244040((int)DAT_003D1A74, 0);
}
