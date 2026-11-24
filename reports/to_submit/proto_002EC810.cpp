// bin: proto
// va: 0x002EC810
// what: Start-up code (a static initializer): stores the name key of "CivilianInterior" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EC810 (Proto 0x002EC810, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00393868[];
extern "C" int DAT_00462EDC;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002EC810(void)
{
    DAT_00462EDC = sub_00201440((int)DAT_00393868, 0);
}
