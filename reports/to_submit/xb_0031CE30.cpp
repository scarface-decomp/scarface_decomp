// bin: xb
// va: 0x0031CE30
// what: Start-up code (a static initializer): stores the name key of "crateFloatingA" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031CE30 (0x0031CE30, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D838[];
extern "C" int DAT_004901CC;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_0031CE30(void)
{
    DAT_004901CC = sub_00243FA0((int)DAT_0039D838, 0);
}
