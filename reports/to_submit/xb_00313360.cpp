// bin: xb
// va: 0x00313360
// what: Start-up code (a static initializer): stores the name key of "StreetLightShape" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313360 (0x00313360, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A0370[];
extern "C" int DAT_004758E0;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00313360(void)
{
    DAT_004758E0 = sub_00244040((int)DAT_003A0370, 0);
}
