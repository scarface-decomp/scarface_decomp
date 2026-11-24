// bin: xb
// va: 0x0031B000
// what: Start-up code (a static initializer): stores the name key of "health" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B000 (0x0031B000, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C3688[];
extern "C" int DAT_0048E698;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031B000(void)
{
    DAT_0048E698 = sub_00244040((int)DAT_003C3688, 0);
}
