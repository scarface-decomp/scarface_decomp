// bin: xb
// va: 0x00313420
// what: 
// tool: the portal's starter code (no AI)

// sub_00313420 (0x00313420, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A0AA0[];
extern "C" int DAT_00475920;
extern "C" int __cdecl sub_0028E510(int);

void __cdecl sub_00313420(void)
{
    DAT_00475920 = sub_0028E510((int)DAT_003A0AA0);
}
