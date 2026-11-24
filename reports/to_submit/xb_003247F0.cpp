// bin: xb
// va: 0x003247F0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003247F0 (0x003247F0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0042E40C;
extern "C" int DAT_0042E410;
extern "C" unsigned short DAT_0042E418;
extern "C" unsigned short DAT_0042E41A;
extern "C" unsigned short DAT_0042E41E;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_003247F0(void)
{
    DAT_0042E40C = (int)DAT_0039D4E4;
    sub_00027600(DAT_0042E410);
    DAT_0042E410 = 0;
    DAT_0042E418 = 0;
    DAT_0042E41A = 0;
    DAT_0042E41E = 0;
    return 0;
}
