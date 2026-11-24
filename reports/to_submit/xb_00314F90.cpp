// bin: xb
// va: 0x00314F90
// what: Start-up code (a static initializer): stores the name key of "Forward" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314F90 (0x00314F90, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A4B88[];
extern "C" int DAT_00486758;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00314F90(void)
{
    DAT_00486758 = sub_00243FA0((int)DAT_003A4B88, 0);
}
