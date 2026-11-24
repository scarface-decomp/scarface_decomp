// bin: xb
// va: 0x00319260
// what: Start-up code (a static initializer): stores the name key of "MainPlayerReloadSpeed" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00319260 (0x00319260, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B5DB4[];
extern "C" int DAT_0048BF08;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00319260(void)
{
    DAT_0048BF08 = sub_00244040((int)DAT_003B5DB4, 0);
}
