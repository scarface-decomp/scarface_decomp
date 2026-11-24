// bin: proto
// va: 0x002E7190
// what: Start-up code (a static initializer): stores the name key of "LookTutorial_InputRightL1" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7190 (Proto 0x002E7190, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039C6D0[];
extern "C" int DAT_0045ED94;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002E7190(void)
{
    DAT_0045ED94 = sub_00201440((int)DAT_0039C6D0, 0);
}
