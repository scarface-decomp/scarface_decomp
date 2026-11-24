// bin: proto
// va: 0x002F6BB0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F6BB0 (Proto 0x002F6BB0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_004213FC;
extern "C" int DAT_00421400;
extern "C" unsigned short DAT_00421408;
extern "C" unsigned short DAT_0042140A;
extern "C" unsigned short DAT_0042140E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F6BB0(void)
{
    DAT_004213FC = (int)DAT_0037CCF4;
    sub_00025160(DAT_00421400);
    DAT_00421400 = 0;
    DAT_00421408 = 0;
    DAT_0042140A = 0;
    DAT_0042140E = 0;
    return 0;
}
