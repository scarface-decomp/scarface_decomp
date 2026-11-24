// bin: xb
// va: 0x00317F10
// what: Start-up code (a static initializer): stores the name key of "CharacterInventoryGroup" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317F10 (0x00317F10, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B4618[];
extern "C" int DAT_0048AA90;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00317F10(void)
{
    DAT_0048AA90 = sub_00244040((int)DAT_003B4618, 0);
}
