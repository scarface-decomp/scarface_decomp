// bin: xb
// va: 0x00313250
// what: Start-up code (a static initializer): stores the name key of "StreetLightShape" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313250 (0x00313250, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A0370[];
extern "C" int DAT_00474E40;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00313250(void)
{
    DAT_00474E40 = sub_00244040((int)DAT_003A0370, 0);
}
