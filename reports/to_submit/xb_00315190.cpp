// bin: xb
// va: 0x00315190
// what: Start-up code (a static initializer): stores the name key of "ThrottleUp" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315190 (0x00315190, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A4C2C[];
extern "C" int DAT_00486798;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00315190(void)
{
    DAT_00486798 = sub_00243FA0((int)DAT_003A4C2C, 0);
}
