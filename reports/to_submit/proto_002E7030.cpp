// bin: proto
// va: 0x002E7030
// what: Start-up code (a static initializer): stores the name key of "exotics_menu_activated" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E7030 (Proto 0x002E7030, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00396ECC[];
extern "C" int DAT_0045E030;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002E7030(void)
{
    DAT_0045E030 = sub_00201440((int)DAT_00396ECC, 0);
}
