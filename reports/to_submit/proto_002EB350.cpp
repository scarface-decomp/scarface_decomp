// bin: proto
// va: 0x002EB350
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB350 (Proto 0x002EB350, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065500(int, int, int, int, int, int);
};

extern "C" char DAT_00425F88[];
extern "C" char DAT_00425F9C[];
extern "C" Object DAT_00461B50;
extern "C" char sub_001DAC50[];

void __cdecl sub_002EB350(void)
{
    DAT_00461B50.sub_00065500((int)DAT_00425F9C, (int)DAT_00425F88, (int)sub_001DAC50, 0, 2, 2);
}
