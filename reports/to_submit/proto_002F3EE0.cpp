// bin: proto
// va: 0x002F3EE0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F3EE0 (Proto 0x002F3EE0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041112C;
extern "C" int DAT_00411130;
extern "C" unsigned short DAT_00411138;
extern "C" unsigned short DAT_0041113A;
extern "C" unsigned short DAT_0041113E;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F3EE0(void)
{
    DAT_0041112C = (int)DAT_0037CCF4;
    sub_00025160(DAT_00411130);
    DAT_00411130 = 0;
    DAT_00411138 = 0;
    DAT_0041113A = 0;
    DAT_0041113E = 0;
    return 0;
}
