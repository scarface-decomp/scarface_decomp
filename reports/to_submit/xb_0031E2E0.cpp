// bin: xb
// va: 0x0031E2E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031E2E0 (0x0031E2E0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0044C644[];
extern "C" char DAT_0044C668[];
extern "C" Object DAT_00490948;
extern "C" char sub_00216630[];

void __cdecl sub_0031E2E0(void)
{
    DAT_00490948.sub_0006F830((int)DAT_0044C668, (int)DAT_0044C644, (int)sub_00216630, 0, 3, 3);
}
