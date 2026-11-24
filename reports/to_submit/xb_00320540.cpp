// bin: xb
// va: 0x00320540
// what: Start-up code (a static initializer): stores the name key of "wait_key" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320540 (0x00320540, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D3428[];
extern "C" int DAT_00492924;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00320540(void)
{
    DAT_00492924 = sub_00243FA0((int)DAT_003D3428, 0);
}
