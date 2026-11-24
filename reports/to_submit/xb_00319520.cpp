// bin: xb
// va: 0x00319520
// what: Start-up code (a static initializer): stores the name key of "exotics_menu_activated" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319520 (0x00319520, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B9614[];
extern "C" int DAT_0048C1C8;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00319520(void)
{
    DAT_0048C1C8 = sub_00243FA0((int)DAT_003B9614, 0);
}
