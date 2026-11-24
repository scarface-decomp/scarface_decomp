// bin: xb
// va: 0x00315520
// what: Start-up code (a static initializer): stores the name key of "MNIS_S01_0_Skull_Kills_Tony_Balcony" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00315520 (0x00315520, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A5E1C[];
extern "C" int DAT_004870D8;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00315520(void)
{
    DAT_004870D8 = sub_00244040((int)DAT_003A5E1C, 0);
}
