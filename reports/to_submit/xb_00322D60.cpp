// bin: xb
// va: 0x00322D60
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00322D60 (0x00322D60, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0041DEC4;
extern "C" unsigned short DAT_0041DECC;
extern "C" unsigned short DAT_0041DECE;
extern "C" unsigned short DAT_0041DED2;
extern "C" void __cdecl sub_00027600(int);

int __cdecl sub_00322D60(void)
{
    sub_00027600(DAT_0041DEC4);
    DAT_0041DEC4 = 0;
    DAT_0041DECC = 0;
    DAT_0041DECE = 0;
    DAT_0041DED2 = 0;
    return 0;
}
