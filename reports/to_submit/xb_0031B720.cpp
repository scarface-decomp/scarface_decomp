// bin: xb
// va: 0x0031B720
// what: Start-up code (a static initializer): stores the name key of "Cal50" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B720 (0x0031B720, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A5C54[];
extern "C" int DAT_0048ECD0;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_0031B720(void)
{
    DAT_0048ECD0 = sub_00243FA0((int)DAT_003A5C54, 0);
}
