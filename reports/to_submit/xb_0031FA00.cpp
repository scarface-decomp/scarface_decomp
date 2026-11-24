// bin: xb
// va: 0x0031FA00
// what: Start-up code (a static initializer): stores the name key of "DWStreetDealer" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FA00 (0x0031FA00, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B5B78[];
extern "C" int DAT_00491F28;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_0031FA00(void)
{
    DAT_00491F28 = sub_00243FA0((int)DAT_003B5B78, 0);
}
