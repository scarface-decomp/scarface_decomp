// bin: proto
// va: 0x002E71B0
// what: Start-up code (a static initializer): stores the name key of "LookTutorial_InputRightR1" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E71B0 (Proto 0x002E71B0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039C6EC[];
extern "C" int DAT_0045ED98;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002E71B0(void)
{
    DAT_0045ED98 = sub_00201440((int)DAT_0039C6EC, 0);
}
