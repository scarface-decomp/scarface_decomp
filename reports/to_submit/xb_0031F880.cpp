// bin: xb
// va: 0x0031F880
// what: Start-up code (a static initializer): stores the name key of "EHE_CALLOUT_LARGE" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F880 (0x0031F880, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D1B20[];
extern "C" int DAT_00491EC4;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031F880(void)
{
    DAT_00491EC4 = sub_00244040((int)DAT_003D1B20, 0);
}
