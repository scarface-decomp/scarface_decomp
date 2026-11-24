// bin: xb
// va: 0x00315050
// what: Start-up code (a static initializer): stores the name key of "Up" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315050 (0x00315050, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A4BCC[];
extern "C" int DAT_00486770;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00315050(void)
{
    DAT_00486770 = sub_00243FA0((int)DAT_003A4BCC, 0);
}
