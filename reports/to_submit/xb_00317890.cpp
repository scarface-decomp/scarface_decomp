// bin: xb
// va: 0x00317890
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317890 (0x00317890, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042E788[];
extern "C" char DAT_0042E7A0[];
extern "C" Object DAT_0048A368;
extern "C" char sub_0015C580[];

void __cdecl sub_00317890(void)
{
    DAT_0048A368.sub_0006F830((int)DAT_0042E7A0, (int)DAT_0042E788, (int)sub_0015C580, 0, 3, 3);
}
