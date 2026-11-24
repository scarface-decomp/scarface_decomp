// bin: xb
// va: 0x0031B5A0
// what: Start-up code (a static initializer): stores the name key of "beamOn" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031B5A0 (0x0031B5A0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003C598C[];
extern "C" int DAT_0048EBEC;
extern "C" int __cdecl sub_00243FA0(int, int);

void __cdecl sub_0031B5A0(void)
{
    DAT_0048EBEC = sub_00243FA0((int)DAT_003C598C, 0);
}
