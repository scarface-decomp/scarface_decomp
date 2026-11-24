// bin: xb
// va: 0x0031CED0
// what: Start-up code (a static initializer): stores the name key of "TargetSet" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031CED0 (0x0031CED0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D858[];
extern "C" int DAT_00490278;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031CED0(void)
{
    DAT_00490278 = sub_00244040((int)DAT_0039D858, 0);
}
