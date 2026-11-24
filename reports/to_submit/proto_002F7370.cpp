// bin: proto
// va: 0x002F7370
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F7370 (Proto 0x002F7370, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_00425A60;
extern "C" int DAT_00425A64;
extern "C" unsigned short DAT_00425A6C;
extern "C" unsigned short DAT_00425A6E;
extern "C" unsigned short DAT_00425A72;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F7370(void)
{
    DAT_00425A60 = (int)DAT_0037CCF4;
    sub_00025160(DAT_00425A64);
    DAT_00425A64 = 0;
    DAT_00425A6C = 0;
    DAT_00425A6E = 0;
    DAT_00425A72 = 0;
    return 0;
}
