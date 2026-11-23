// bin: xb
// va: 0x003207E0
// what: 
// tool: the portal's starter code (no AI)

// sub_003207E0 (0x003207E0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00457BBC;
extern "C" int DAT_00492C2C;
extern "C" int __cdecl sub_0028E510(int);

void __cdecl sub_003207E0(void)
{
    DAT_00492C2C = sub_0028E510(DAT_00457BBC);
}
