// bin: xb
// va: 0x0031FC00
// what: Start-up code (a static initializer): stores the name key of "FightBetting_HUD" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FC00 (0x0031FC00, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D2F0C[];
extern "C" int DAT_00492048;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031FC00(void)
{
    DAT_00492048 = sub_00244040((int)DAT_003D2F0C, 0);
}
