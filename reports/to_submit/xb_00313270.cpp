// bin: xb
// va: 0x00313270
// what: Start-up code (a static initializer): stores the name key of "wayPointBBShaftTallShape" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313270 (0x00313270, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A0384[];
extern "C" int DAT_00474E44;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00313270(void)
{
    DAT_00474E44 = sub_00243FA0((int)DAT_003A0384, 0);
}
