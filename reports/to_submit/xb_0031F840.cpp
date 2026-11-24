// bin: xb
// va: 0x0031F840
// what: Start-up code (a static initializer): stores the name key of "IntersectionObjectSet" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031F840 (0x0031F840, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003D0B60[];
extern "C" int DAT_00491EB4;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031F840(void)
{
    DAT_00491EB4 = sub_00244040((int)DAT_003D0B60, 0);
}
