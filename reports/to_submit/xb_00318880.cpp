// bin: xb
// va: 0x00318880
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00318880 (0x00318880, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F790(int, int, int, int, int, int);
};

extern "C" char DAT_0043006C[];
extern "C" char DAT_00430078[];
extern "C" Object DAT_0048B680;
extern "C" char sub_001784A0[];

void __cdecl sub_00318880(void)
{
    DAT_0048B680.sub_0006F790((int)DAT_00430078, (int)DAT_0043006C, (int)sub_001784A0, 0, 3, 3);
}
