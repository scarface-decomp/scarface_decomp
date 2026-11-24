// bin: xb
// va: 0x0031F600
// what: Start-up code (a static initializer): stores the name key of "EHE_COP_VISIBILITY_BUBBLE2" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F600 (0x0031F600, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BB714[];
extern "C" int DAT_00491E24;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031F600(void)
{
    DAT_00491E24 = sub_00244040((int)DAT_003BB714, 0);
}
