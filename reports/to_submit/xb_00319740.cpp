// bin: xb
// va: 0x00319740
// what: Start-up code (a static initializer): stores the name key of "LookTutorial_InputRightL1" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319740 (0x00319740, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C101C[];
extern "C" int DAT_0048D104;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00319740(void)
{
    DAT_0048D104 = sub_00243FA0((int)DAT_003C101C, 0);
}
