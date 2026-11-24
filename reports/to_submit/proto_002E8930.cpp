// bin: proto
// va: 0x002E8930
// what: Start-up code (a static initializer): stores the name key of "discTurningOn" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8930 (Proto 0x002E8930, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039FCAC[];
extern "C" int DAT_00460188;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002E8930(void)
{
    DAT_00460188 = sub_00201440((int)DAT_0039FCAC, 0);
}
