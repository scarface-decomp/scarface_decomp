// bin: xb
// va: 0x0031F6C0
// what: Start-up code (a static initializer): stores the name key of "EHE_COP_VISIBILITY_BUBBLE8" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F6C0 (0x0031F6C0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BB66C[];
extern "C" int DAT_00491E54;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031F6C0(void)
{
    DAT_00491E54 = sub_00244040((int)DAT_003BB66C, 0);
}
