// bin: xb
// va: 0x00318160
// what: Start-up code (a static initializer): stores the name key of "Entry0" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318160 (0x00318160, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003AF444[];
extern "C" int DAT_0048ADFC;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_00318160(void)
{
    DAT_0048ADFC = sub_00243FA0((int)DAT_003AF444, 0);
}
