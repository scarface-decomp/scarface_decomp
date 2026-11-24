// bin: xb
// va: 0x0031F720
// what: Start-up code (a static initializer): stores the name key of "CopRespondersSet" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F720 (0x0031F720, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B5324[];
extern "C" int DAT_00491E6C;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031F720(void)
{
    DAT_00491E6C = sub_00244040((int)DAT_003B5324, 0);
}
