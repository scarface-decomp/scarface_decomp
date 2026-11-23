// bin: xb
// va: 0x0031B800
// what: 
// tool: the portal's starter code (no AI)

// sub_0031B800 (0x0031B800, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C5DBC[];
extern "C" int DAT_0048ECEC;
extern "C" int __cdecl sub_0028E510(int);

void __cdecl sub_0031B800(void)
{
    DAT_0048ECEC = sub_0028E510((int)DAT_003C5DBC);
}
