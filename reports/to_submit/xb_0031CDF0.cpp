// bin: xb
// va: 0x0031CDF0
// what: 
// tool: the portal's starter code (no AI)

// sub_0031CDF0 (0x0031CDF0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A426C[];
extern "C" int DAT_004900E0;
extern "C" int __cdecl sub_0028E510(int);

void __cdecl sub_0031CDF0(void)
{
    DAT_004900E0 = sub_0028E510((int)DAT_003A426C);
}
