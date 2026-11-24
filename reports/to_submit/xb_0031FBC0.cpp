// bin: xb
// va: 0x0031FBC0
// what: Start-up code (a static initializer): stores the name key of "EHE_EXOTICS_HUD" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FBC0 (0x0031FBC0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BB888[];
extern "C" int DAT_00492038;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031FBC0(void)
{
    DAT_00492038 = sub_00244040((int)DAT_003BB888, 0);
}
