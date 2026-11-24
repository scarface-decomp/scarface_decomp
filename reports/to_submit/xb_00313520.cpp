// bin: xb
// va: 0x00313520
// what: Start-up code (a static initializer): stores the name key of "BuildingLightsShape" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313520 (0x00313520, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A0F40[];
extern "C" int DAT_00475940;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00313520(void)
{
    DAT_00475940 = sub_00244040((int)DAT_003A0F40, 0);
}
