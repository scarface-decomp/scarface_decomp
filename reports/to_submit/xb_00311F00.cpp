// bin: xb
// va: 0x00311F00
// what: Start-up code (a static initializer): stores the name key of "closing" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00311F00 (0x00311F00, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039DDF0[];
extern "C" int DAT_00471444;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00311F00(void)
{
    DAT_00471444 = sub_00243FA0((int)DAT_0039DDF0, 0);
}
