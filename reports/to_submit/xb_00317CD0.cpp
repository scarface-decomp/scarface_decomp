// bin: xb
// va: 0x00317CD0
// what: Start-up code (a static initializer): stores the name key of "WallCover" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317CD0 (0x00317CD0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B3808[];
extern "C" int DAT_0048A8A8;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00317CD0(void)
{
    DAT_0048A8A8 = sub_00244040((int)DAT_003B3808, 0);
}
