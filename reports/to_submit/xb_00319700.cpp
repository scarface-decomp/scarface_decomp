// bin: xb
// va: 0x00319700
// what: Start-up code (a static initializer): stores the name key of "LookTutorial_InputRightXAxis" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319700 (0x00319700, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C0FDC[];
extern "C" int DAT_0048D0FC;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00319700(void)
{
    DAT_0048D0FC = sub_00243FA0((int)DAT_003C0FDC, 0);
}
