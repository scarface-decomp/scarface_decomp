// bin: xb
// va: 0x00316810
// what: Start-up code (a static initializer): stores the name key of "Ambient" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316810 (0x00316810, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AAA90[];
extern "C" int DAT_00489464;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_00316810(void)
{
    DAT_00489464 = sub_00244040((int)DAT_003AAA90, 0);
}
