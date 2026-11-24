// bin: xb
// va: 0x003204E0
// what: Start-up code (a static initializer): stores the name key of "start" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003204E0 (0x003204E0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A33B4[];
extern "C" int DAT_00492918;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_003204E0(void)
{
    DAT_00492918 = sub_00243FA0((int)DAT_003A33B4, 0);
}
