// bin: proto
// va: 0x002E8250
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8250 (Proto 0x002E8250, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00411874[];
extern "C" char DAT_00411888[];
extern "C" Object DAT_0045FD6C;
extern "C" char sub_0018BDB0[];

void __cdecl sub_002E8250(void)
{
    DAT_0045FD6C.sub_00065550((int)DAT_00411888, (int)DAT_00411874, (int)sub_0018BDB0, 0, 3, 3);
}
