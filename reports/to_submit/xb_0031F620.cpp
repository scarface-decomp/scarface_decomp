// bin: xb
// va: 0x0031F620
// what: Start-up code (a static initializer): stores the name key of "EHE_COP_VISIBILITY_BUBBLE3" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F620 (0x0031F620, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BB6F8[];
extern "C" int DAT_00491E2C;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031F620(void)
{
    DAT_00491E2C = sub_00244040((int)DAT_003BB6F8, 0);
}
