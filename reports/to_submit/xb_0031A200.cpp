// bin: xb
// va: 0x0031A200
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031A200 (0x0031A200, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_00436F5C[];
extern "C" Object DAT_0048D9D4;
extern "C" char sub_001BE370[];

void __cdecl sub_0031A200(void)
{
    DAT_0048D9D4.sub_0006F830(0, (int)DAT_00436F5C, (int)sub_001BE370, 0, 7, 8);
}
