// bin: proto
// va: 0x002F58D0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F58D0 (Proto 0x002F58D0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004191F8;
extern "C" int DAT_004191FC;
extern "C" unsigned short DAT_00419204;
extern "C" unsigned short DAT_00419206;
extern "C" unsigned short DAT_0041920A;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F58D0(void)
{
    DAT_004191F8 = (int)DAT_0037CCF4;
    sub_00025160(DAT_004191FC);
    DAT_004191FC = 0;
    DAT_00419204 = 0;
    DAT_00419206 = 0;
    DAT_0041920A = 0;
    return 0;
}
