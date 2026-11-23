// bin: xb
// va: 0x00320860
// what: 
// tool: the portal's starter code (no AI)

// sub_00320860 (0x00320860, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00457BB8;
extern "C" int DAT_00492C34;
extern "C" int __cdecl sub_0028E510(int);

void __cdecl sub_00320860(void)
{
    DAT_00492C34 = sub_0028E510(DAT_00457BB8);
}
