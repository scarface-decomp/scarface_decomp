// bin: xb
// va: 0x0031CA30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031CA30 (0x0031CA30, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F880(int, int, int, int, int, int);
};

extern "C" char DAT_0043E388[];
extern "C" char DAT_0043E3A4[];
extern "C" Object DAT_0048FA54;
extern "C" char sub_001EE310[];

void __cdecl sub_0031CA30(void)
{
    DAT_0048FA54.sub_0006F880((int)DAT_0043E3A4, (int)DAT_0043E388, (int)sub_001EE310, 0, 2, 2);
}
