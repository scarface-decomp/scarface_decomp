// bin: xb
// va: 0x0031B840
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B840 (0x0031B840, 89 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C5DD4[];
extern "C" char DAT_003C5DE4[];
extern "C" char DAT_003C5DF4[];
extern "C" char DAT_003C5E04[];
extern "C" char DAT_003C5E14[];
extern "C" int DAT_0048ECF4;
extern "C" int DAT_0048ECF8;
extern "C" int DAT_0048ECFC;
extern "C" int DAT_0048ED00;
extern "C" int DAT_0048ED04;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_0031B840(void)
{
    DAT_0048ECF4 = sub_00243FA0((int)DAT_003C5E14, 0);
    DAT_0048ECF8 = sub_00243FA0((int)DAT_003C5E04, 0);
    DAT_0048ECFC = sub_00243FA0((int)DAT_003C5DF4, 0);
    DAT_0048ED00 = sub_00243FA0((int)DAT_003C5DE4, 0);
    DAT_0048ED04 = sub_00243FA0((int)DAT_003C5DD4, 0);
}
