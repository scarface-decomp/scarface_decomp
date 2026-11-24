// bin: xb
// va: 0x00314F70
// what: Start-up code (a static initializer): stores the name key of "TightTurn" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314F70 (0x00314F70, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A4B7C[];
extern "C" int DAT_00486754;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00314F70(void)
{
    DAT_00486754 = sub_00243FA0((int)DAT_003A4B7C, 0);
}
