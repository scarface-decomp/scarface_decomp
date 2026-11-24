// bin: xb
// va: 0x0031CFD0
// what: Start-up code (a static initializer): stores the name key of "TargetingTrapezoid_Boat_Locked" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031CFD0 (0x0031CFD0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CA950[];
extern "C" int DAT_004902A0;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_0031CFD0(void)
{
    DAT_004902A0 = sub_00243FA0((int)DAT_003CA950, 0);
}
