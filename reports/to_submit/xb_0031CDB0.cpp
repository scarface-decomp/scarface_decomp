// bin: xb
// va: 0x0031CDB0
// what: 
// tool: the portal's starter code (no AI)

// sub_0031CDB0 (0x0031CDB0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C9ED8[];
extern "C" int DAT_004900D8;
extern "C" int __cdecl sub_0028E510(int);

void __cdecl sub_0031CDB0(void)
{
    DAT_004900D8 = sub_0028E510((int)DAT_003C9ED8);
}
