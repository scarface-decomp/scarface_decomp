// bin: xb
// va: 0x00315090
// what: Start-up code (a static initializer): stores the name key of "EBrake" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315090 (0x00315090, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A4BD8[];
extern "C" int DAT_00486778;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00315090(void)
{
    DAT_00486778 = sub_00243FA0((int)DAT_003A4BD8, 0);
}
