// bin: xb
// va: 0x0031E520
// what: Start-up code (a static initializer): stores the name key of "GameCarSet" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E520 (0x0031E520, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CFB60[];
extern "C" int DAT_00490BC4;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031E520(void)
{
    DAT_00490BC4 = sub_00244040((int)DAT_003CFB60, 0);
}
