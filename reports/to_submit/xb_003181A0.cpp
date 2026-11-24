// bin: xb
// va: 0x003181A0
// what: Start-up code (a static initializer): stores the name key of "Entry2" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003181A0 (0x003181A0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B5780[];
extern "C" int DAT_0048AE04;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_003181A0(void)
{
    DAT_0048AE04 = sub_00243FA0((int)DAT_003B5780, 0);
}
