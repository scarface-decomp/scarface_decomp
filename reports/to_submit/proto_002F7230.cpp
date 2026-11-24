// bin: proto
// va: 0x002F7230
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F7230 (Proto 0x002F7230, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004253F8;
extern "C" int DAT_004253FC;
extern "C" unsigned short DAT_00425404;
extern "C" unsigned short DAT_00425406;
extern "C" unsigned short DAT_0042540A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F7230(void)
{
    DAT_004253F8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004253FC);
    DAT_004253FC = 0;
    DAT_00425404 = 0;
    DAT_00425406 = 0;
    DAT_0042540A = 0;
    return 0;
}
