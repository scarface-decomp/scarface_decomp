// bin: xb
// va: 0x00313380
// what: Start-up code (a static initializer): stores the name key of "MiamiNightFillShape" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313380 (0x00313380, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A072C[];
extern "C" int DAT_004758E4;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00313380(void)
{
    DAT_004758E4 = sub_00244040((int)DAT_003A072C, 0);
}
