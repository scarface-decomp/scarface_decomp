// bin: proto
// va: 0x002E7150
// what: Start-up code (a static initializer): stores the name key of "LookTutorial_InputRightXAxis" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7150 (Proto 0x002E7150, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039C690[];
extern "C" int DAT_0045ED8C;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002E7150(void)
{
    DAT_0045ED8C = sub_00201440((int)DAT_0039C690, 0);
}
