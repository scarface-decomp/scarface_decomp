// bin: proto
// va: 0x002E2D50
// what: Start-up code (a static initializer): stores the name key of "WeaponPU" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E2D50 (Proto 0x002E2D50, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003837F8[];
extern "C" int DAT_00453B48;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002E2D50(void)
{
    DAT_00453B48 = sub_00201440((int)DAT_003837F8, 0);
}
