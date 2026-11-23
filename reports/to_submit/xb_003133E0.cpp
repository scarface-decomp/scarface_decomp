// bin: xb
// va: 0x003133E0
// what: 
// tool: the portal's starter code (no AI)

// sub_003133E0 (0x003133E0, 19 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A0A68[];
extern "C" int DAT_00475918;
extern "C" int __cdecl sub_0028E510(int);

void __cdecl sub_003133E0(void)
{
    DAT_00475918 = sub_0028E510((int)DAT_003A0A68);
}
