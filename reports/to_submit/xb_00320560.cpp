// bin: xb
// va: 0x00320560
// what: Start-up code (a static initializer): stores the name key of "message" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320560 (0x00320560, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D3434[];
extern "C" int DAT_00492928;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00320560(void)
{
    DAT_00492928 = sub_00243FA0((int)DAT_003D3434, 0);
}
