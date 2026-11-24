// bin: xb
// va: 0x00315030
// what: Start-up code (a static initializer): stores the name key of "ForwardReverse" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315030 (0x00315030, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A4BBC[];
extern "C" int DAT_0048676C;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00315030(void)
{
    DAT_0048676C = sub_00243FA0((int)DAT_003A4BBC, 0);
}
