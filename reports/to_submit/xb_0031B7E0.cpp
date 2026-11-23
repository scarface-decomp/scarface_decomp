// bin: xb
// va: 0x0031B7E0
// what: 
// tool: the portal's starter code (no AI)

// sub_0031B7E0 (0x0031B7E0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C5DA8[];
extern "C" int DAT_0048ECE8;
extern "C" int __cdecl sub_0028E510(int);

void __cdecl sub_0031B7E0(void)
{
    DAT_0048ECE8 = sub_0028E510((int)DAT_003C5DA8);
}
