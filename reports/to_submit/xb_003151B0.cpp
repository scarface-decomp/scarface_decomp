// bin: xb
// va: 0x003151B0
// what: Start-up code (a static initializer): stores the name key of "Brake" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003151B0 (0x003151B0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A4C38[];
extern "C" int DAT_0048679C;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_003151B0(void)
{
    DAT_0048679C = sub_00243FA0((int)DAT_003A4C38, 0);
}
