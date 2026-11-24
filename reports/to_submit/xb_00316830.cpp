// bin: xb
// va: 0x00316830
// what: Start-up code (a static initializer): stores the name key of "Combat" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316830 (0x00316830, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AAA88[];
extern "C" int DAT_00489468;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00316830(void)
{
    DAT_00489468 = sub_00244040((int)DAT_003AAA88, 0);
}
