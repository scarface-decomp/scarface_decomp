// bin: xb
// va: 0x0031FC40
// what: Start-up code (a static initializer): stores the name key of "Blackjack_HUD" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FC40 (0x0031FC40, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D2F30[];
extern "C" int DAT_00492058;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031FC40(void)
{
    DAT_00492058 = sub_00244040((int)DAT_003D2F30, 0);
}
