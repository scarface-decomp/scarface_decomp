// bin: proto
// va: 0x002F62F0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F62F0 (Proto 0x002F62F0, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CCF4[];
extern "C" int DAT_0041D944;
extern "C" int DAT_0041D948;
extern "C" unsigned short DAT_0041D950;
extern "C" unsigned short DAT_0041D952;
extern "C" unsigned short DAT_0041D956;
extern "C" void __cdecl sub_00025160(int);

int __cdecl sub_002F62F0(void)
{
    DAT_0041D944 = (int)DAT_0037CCF4;
    sub_00025160(DAT_0041D948);
    DAT_0041D948 = 0;
    DAT_0041D950 = 0;
    DAT_0041D952 = 0;
    DAT_0041D956 = 0;
    return 0;
}
