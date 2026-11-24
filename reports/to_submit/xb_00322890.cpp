// bin: xb
// va: 0x00322890
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322890 (0x00322890, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039D4E4[];
extern "C" int DAT_0041ACC4;
extern "C" int DAT_0041ACC8;
extern "C" unsigned short DAT_0041ACD0;
extern "C" unsigned short DAT_0041ACD2;
extern "C" unsigned short DAT_0041ACD6;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00322890(void)
{
    DAT_0041ACC4 = (int)DAT_0039D4E4;
    sub_00027600(DAT_0041ACC8);
    DAT_0041ACC8 = 0;
    DAT_0041ACD0 = 0;
    DAT_0041ACD2 = 0;
    DAT_0041ACD6 = 0;
    return 0;
}
