// bin: xb
// va: 0x00314FB0
// what: Start-up code (a static initializer): stores the name key of "Reverse" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314FB0 (0x00314FB0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A4B90[];
extern "C" int DAT_0048675C;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00314FB0(void)
{
    DAT_0048675C = sub_00243FA0((int)DAT_003A4B90, 0);
}
