// bin: xb
// va: 0x00311D40
// what: Start-up code (a static initializer): stores the name key of "DEC_DecorItemScriptClass" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00311D40 (0x00311D40, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D940[];
extern "C" int DAT_00471170;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00311D40(void)
{
    DAT_00471170 = sub_00243FA0((int)DAT_0039D940, 0);
}
