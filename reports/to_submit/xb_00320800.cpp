// bin: xb
// va: 0x00320800
// what: 
// tool: the portal's starter code (no AI)

// sub_00320800 (0x00320800, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00457BAC;
extern "C" int DAT_00492C38;
extern "C" int __cdecl sub_0028E510(int);

void __cdecl sub_00320800(void)
{
    DAT_00492C38 = sub_0028E510(DAT_00457BAC);
}
