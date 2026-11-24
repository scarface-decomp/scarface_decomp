// bin: xb
// va: 0x0031D030
// what: Start-up code (a static initializer): stores the name key of "Targeting" in a global.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031D030 (0x0031D030, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003B3360[];
extern "C" int DAT_004902B0;
extern "C" int __cdecl sub_00244040(int, int);

void __cdecl sub_0031D030(void)
{
    DAT_004902B0 = sub_00244040((int)DAT_003B3360, 0);
}
