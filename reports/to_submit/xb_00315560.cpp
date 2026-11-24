// bin: xb
// va: 0x00315560
// what: Start-up code (a static initializer): stores the name key of "MNIS_AMB_Tony_Dies_by_Shark" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315560 (0x00315560, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A5E68[];
extern "C" int DAT_004870E0;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00315560(void)
{
    DAT_004870E0 = sub_00244040((int)DAT_003A5E68, 0);
}
