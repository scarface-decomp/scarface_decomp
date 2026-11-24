// bin: xb
// va: 0x00313290
// what: Start-up code (a static initializer): stores the name key of "wayPointBBShaftShortShape" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313290 (0x00313290, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A03A0[];
extern "C" int DAT_00474E48;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00313290(void)
{
    DAT_00474E48 = sub_00243FA0((int)DAT_003A03A0, 0);
}
