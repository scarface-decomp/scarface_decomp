// bin: xb
// va: 0x00320580
// what: Start-up code (a static initializer): stores the name key of "set_callback" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320580 (0x00320580, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D343C[];
extern "C" int DAT_0049292C;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00320580(void)
{
    DAT_0049292C = sub_00243FA0((int)DAT_003D343C, 0);
}
