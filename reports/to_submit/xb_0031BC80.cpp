// bin: xb
// va: 0x0031BC80
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031BC80 (0x0031BC80, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0043ABEC[];
extern "C" char DAT_0043ABFC[];
extern "C" Object DAT_0048EEF8;
extern "C" char sub_001D33E0[];

void __cdecl sub_0031BC80(void)
{
    DAT_0048EEF8.sub_0006F830((int)DAT_0043ABFC, (int)DAT_0043ABEC, (int)sub_001D33E0, 0, 3, 3);
}
