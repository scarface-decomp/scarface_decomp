// bin: xb
// va: 0x003150D0
// what: Start-up code (a static initializer): stores the name key of "DoorControl" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003150D0 (0x003150D0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A4BE8[];
extern "C" int DAT_00486780;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_003150D0(void)
{
    DAT_00486780 = sub_00243FA0((int)DAT_003A4BE8, 0);
}
