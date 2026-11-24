// bin: proto
// va: 0x002E8AD0
// what: Start-up code (a static initializer): stores the name key of "missingProp" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8AD0 (Proto 0x002E8AD0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A003C[];
extern "C" int DAT_00460260;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002E8AD0(void)
{
    DAT_00460260 = sub_00201440((int)DAT_003A003C, 0);
}
