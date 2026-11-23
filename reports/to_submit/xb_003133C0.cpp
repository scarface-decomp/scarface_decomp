// bin: xb
// va: 0x003133C0
// what: 
// tool: the portal's starter code (no AI)

// sub_003133C0 (0x003133C0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A0A4C[];
extern "C" int DAT_00475914;
extern "C" int __cdecl sub_0028E510(int);

void __cdecl sub_003133C0(void)
{
    DAT_00475914 = sub_0028E510((int)DAT_003A0A4C);
}
