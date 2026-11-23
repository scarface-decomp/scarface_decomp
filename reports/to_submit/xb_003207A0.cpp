// bin: xb
// va: 0x003207A0
// what: 
// tool: the portal's starter code (no AI)

// sub_003207A0 (0x003207A0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00457B90;
extern "C" int DAT_00492C08;
extern "C" int __cdecl sub_0028E510(int);

void __cdecl sub_003207A0(void)
{
    DAT_00492C08 = sub_0028E510(DAT_00457B90);
}
