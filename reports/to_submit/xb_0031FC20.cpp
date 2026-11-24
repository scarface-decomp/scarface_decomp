// bin: xb
// va: 0x0031FC20
// what: Start-up code (a static initializer): stores the name key of "SlotMachine_HUD" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031FC20 (0x0031FC20, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D2F20[];
extern "C" int DAT_00492050;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031FC20(void)
{
    DAT_00492050 = sub_00244040((int)DAT_003D2F20, 0);
}
