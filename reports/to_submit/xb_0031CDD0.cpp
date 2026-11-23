// bin: xb
// va: 0x0031CDD0
// what: 
// tool: the portal's starter code (no AI)

// sub_0031CDD0 (0x0031CDD0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C9EE0[];
extern "C" int DAT_004900DC;
extern "C" int __cdecl sub_0028E510(int);

void __cdecl sub_0031CDD0(void)
{
    DAT_004900DC = sub_0028E510((int)DAT_003C9EE0);
}
