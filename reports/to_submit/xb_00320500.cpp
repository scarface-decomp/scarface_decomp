// bin: xb
// va: 0x00320500
// what: Start-up code (a static initializer): stores the name key of "terminate" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320500 (0x00320500, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D3410[];
extern "C" int DAT_0049291C;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00320500(void)
{
    DAT_0049291C = sub_00243FA0((int)DAT_003D3410, 0);
}
