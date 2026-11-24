// bin: xb
// va: 0x0031F5C0
// what: Start-up code (a static initializer): stores the name key of "EHE_DISTANCE_BUBBLE4" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F5C0 (0x0031F5C0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BB74C[];
extern "C" int DAT_00491E14;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031F5C0(void)
{
    DAT_00491E14 = sub_00244040((int)DAT_003BB74C, 0);
}
