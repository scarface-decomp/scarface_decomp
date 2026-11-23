// bin: xb
// va: 0x0031CD90
// what: 
// tool: the portal's starter code (no AI)

// sub_0031CD90 (0x0031CD90, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C5DBC[];
extern "C" int DAT_004900D4;
extern "C" int __cdecl sub_0028E510(int);

void __cdecl sub_0031CD90(void)
{
    DAT_004900D4 = sub_0028E510((int)DAT_003C5DBC);
}
