// bin: xb
// va: 0x003159B0
// what: 
// tool: the portal's starter code (no AI)

// sub_003159B0 (0x003159B0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A5DAC[];
extern "C" int DAT_004875CC;
extern "C" int __cdecl sub_0028E510(int);

void __cdecl sub_003159B0(void)
{
    DAT_004875CC = sub_0028E510((int)DAT_003A5DAC);
}
