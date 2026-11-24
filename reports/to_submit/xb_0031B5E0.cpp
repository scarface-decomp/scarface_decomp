// bin: xb
// va: 0x0031B5E0
// what: Start-up code (a static initializer): stores the name key of "discOn" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B5E0 (0x0031B5E0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C59A4[];
extern "C" int DAT_0048EBF4;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_0031B5E0(void)
{
    DAT_0048EBF4 = sub_00243FA0((int)DAT_003C59A4, 0);
}
