// bin: xb
// va: 0x0031CA70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_0031CA70 (0x0031CA70, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F740(int, int, int, int, int, int);
};

extern "C" char DAT_0043E3E0[];
extern "C" char DAT_0043E3F8[];
extern "C" Object DAT_0048FAAC;
extern "C" char sub_001EE540[];

void __cdecl sub_0031CA70(void)
{
    DAT_0048FAAC.sub_0006F740((int)DAT_0043E3F8, (int)DAT_0043E3E0, (int)sub_001EE540, 0, 2, 2);
}
