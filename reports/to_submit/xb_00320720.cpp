// bin: xb
// va: 0x00320720
// what: 
// tool: the portal's starter code (no AI)

// sub_00320720 (0x00320720, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00457B80;
extern "C" int DAT_00492C04;
extern "C" int __cdecl sub_0028E510(int);

void __cdecl sub_00320720(void)
{
    DAT_00492C04 = sub_0028E510(DAT_00457B80);
}
