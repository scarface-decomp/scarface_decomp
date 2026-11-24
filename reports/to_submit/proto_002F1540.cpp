// bin: proto
// va: 0x002F1540
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F1540 (Proto 0x002F1540, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_003FF52C;
extern "C" int DAT_003FF530;
extern "C" unsigned short DAT_003FF538;
extern "C" unsigned short DAT_003FF53A;
extern "C" unsigned short DAT_003FF53E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F1540(void)
{
    DAT_003FF52C = (int)DAT_0037CCF4;
    sub_00025160(DAT_003FF530);
    DAT_003FF530 = 0;
    DAT_003FF538 = 0;
    DAT_003FF53A = 0;
    DAT_003FF53E = 0;
    return 0;
}
