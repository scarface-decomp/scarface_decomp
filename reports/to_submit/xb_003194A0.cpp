// bin: xb
// va: 0x003194A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003194A0 (0x003194A0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00434018[];
extern "C" Object DAT_0048C13C;
extern "C" char sub_00189680[];

void __cdecl sub_003194A0(void)
{
    DAT_0048C13C.sub_0006F830(0, (int)DAT_00434018, (int)sub_00189680, 0, 1, 2);
}
