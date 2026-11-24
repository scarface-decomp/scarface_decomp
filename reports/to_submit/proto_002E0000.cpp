// bin: proto
// va: 0x002E0000
// what: Start-up code (a static initializer): stores the name key of "shake" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0000 (Proto 0x002E0000, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037D564[];
extern "C" int DAT_004467BC;
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_002E0000(void)
{
    DAT_004467BC = sub_00201440((int)DAT_0037D564, 0);
}
