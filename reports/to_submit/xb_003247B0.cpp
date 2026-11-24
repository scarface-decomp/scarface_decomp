// bin: xb
// va: 0x003247B0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003247B0 (0x003247B0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042E3DC;
extern "C" int DAT_0042E3E0;
extern "C" unsigned short DAT_0042E3E8;
extern "C" unsigned short DAT_0042E3EA;
extern "C" unsigned short DAT_0042E3EE;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003247B0(void)
{
    DAT_0042E3DC = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042E3E0);
    DAT_0042E3E0 = 0;
    DAT_0042E3E8 = 0;
    DAT_0042E3EA = 0;
    DAT_0042E3EE = 0;
    return 0;
}
