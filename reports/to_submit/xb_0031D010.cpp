// bin: xb
// va: 0x0031D010
// what: Start-up code (a static initializer): stores the name key of "TargetingTrapezoid_Rage" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031D010 (0x0031D010, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003CA994[];
extern "C" int DAT_004902A8;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_0031D010(void)
{
    DAT_004902A8 = sub_00243FA0((int)DAT_003CA994, 0);
}
