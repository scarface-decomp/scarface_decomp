// bin: xb
// va: 0x00314870
// what: Start-up code (a static initializer): stores the name key of "persist_destroyed" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314870 (0x00314870, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A4204[];
extern "C" int DAT_00481574;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00314870(void)
{
    DAT_00481574 = sub_00244040((int)DAT_003A4204, 0);
}
