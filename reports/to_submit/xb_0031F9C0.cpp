// bin: xb
// va: 0x0031F9C0
// what: Start-up code (a static initializer): stores the name key of "DWHenchman" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F9C0 (0x0031F9C0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B5B60[];
extern "C" int DAT_00491F20;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_0031F9C0(void)
{
    DAT_00491F20 = sub_00243FA0((int)DAT_003B5B60, 0);
}
