// bin: xb
// va: 0x0031AF60
// what: Start-up code (a static initializer): stores the name key of "ignoreMinMax" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031AF60 (0x0031AF60, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C364C[];
extern "C" int DAT_0048E684;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031AF60(void)
{
    DAT_0048E684 = sub_00244040((int)DAT_003C364C, 0);
}
