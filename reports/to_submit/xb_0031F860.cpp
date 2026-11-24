// bin: xb
// va: 0x0031F860
// what: Start-up code (a static initializer): stores the name key of "WeaponPickupSet" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F860 (0x0031F860, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D1B10[];
extern "C" int DAT_00491EBC;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031F860(void)
{
    DAT_00491EBC = sub_00244040((int)DAT_003D1B10, 0);
}
