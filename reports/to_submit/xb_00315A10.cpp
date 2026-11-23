// bin: xb
// va: 0x00315A10
// what: 
// tool: the portal's starter code (no AI)

// sub_00315A10 (0x00315A10, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A6384[];
extern "C" int DAT_004875D8;
extern "C" int __cdecl sub_0028E510(int);

void __cdecl sub_00315A10(void)
{
    DAT_004875D8 = sub_0028E510((int)DAT_003A6384);
}
