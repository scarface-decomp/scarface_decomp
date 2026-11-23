// bin: xb
// va: 0x00315A90
// what: 
// tool: the portal's starter code (no AI)

// sub_00315A90 (0x00315A90, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A63DC[];
extern "C" int DAT_004875E8;
extern "C" int __cdecl sub_0028E510(int);

void __cdecl sub_00315A90(void)
{
    DAT_004875E8 = sub_0028E510((int)DAT_003A63DC);
}
