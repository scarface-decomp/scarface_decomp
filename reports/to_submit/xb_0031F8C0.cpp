// bin: xb
// va: 0x0031F8C0
// what: Start-up code (a static initializer): stores the name key of "EHE_VISIBILITY_HUD" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F8C0 (0x0031F8C0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BB7C8[];
extern "C" int DAT_00491ED4;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031F8C0(void)
{
    DAT_00491ED4 = sub_00244040((int)DAT_003BB7C8, 0);
}
