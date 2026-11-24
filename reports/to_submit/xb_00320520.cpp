// bin: xb
// va: 0x00320520
// what: Start-up code (a static initializer): stores the name key of "enable_keys" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00320520 (0x00320520, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D341C[];
extern "C" int DAT_00492920;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00320520(void)
{
    DAT_00492920 = sub_00243FA0((int)DAT_003D341C, 0);
}
