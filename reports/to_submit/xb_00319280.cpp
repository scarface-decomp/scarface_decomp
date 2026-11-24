// bin: xb
// va: 0x00319280
// what: Start-up code (a static initializer): stores the name key of "MainCharacter" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319280 (0x00319280, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B3E70[];
extern "C" int DAT_0048BF88;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00319280(void)
{
    DAT_0048BF88 = sub_00244040((int)DAT_003B3E70, 0);
}
