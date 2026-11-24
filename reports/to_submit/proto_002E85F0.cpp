// bin: proto
// va: 0x002E85F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E85F0 (Proto 0x002E85F0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00065550(int, int, int, int, int, int);
};

extern "C" char DAT_00412314[];
extern "C" char DAT_0041231C[];
extern "C" Object DAT_00460004;
extern "C" char sub_00191C50[];

void __cdecl sub_002E85F0(void)
{
    DAT_00460004.sub_00065550((int)DAT_0041231C, (int)DAT_00412314, (int)sub_00191C50, 0, 2, 2);
}
