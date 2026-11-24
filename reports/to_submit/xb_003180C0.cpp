// bin: xb
// va: 0x003180C0
// what: Start-up code (a static initializer): stores the name key of "inv_type" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003180C0 (0x003180C0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B45C8[];
extern "C" int DAT_0048ADCC;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_003180C0(void)
{
    DAT_0048ADCC = sub_00244040((int)DAT_003B45C8, 0);
}
