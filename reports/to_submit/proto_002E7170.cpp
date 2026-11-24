// bin: proto
// va: 0x002E7170
// what: Start-up code (a static initializer): stores the name key of "LookTutorial_InputRightYAxis" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7170 (Proto 0x002E7170, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039C6B0[];
extern "C" int DAT_0045ED90;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002E7170(void)
{
    DAT_0045ED90 = sub_00201440((int)DAT_0039C6B0, 0);
}
