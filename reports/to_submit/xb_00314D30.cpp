// bin: xb
// va: 0x00314D30
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00314D30 (0x00314D30, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000997E0(int);
};

extern "C" Object DAT_00481B90;
extern "C" char sub_00323080[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00314D30(void)
{
    DAT_00481B90.sub_000997E0(-1);
    sub_002FBBEF((int)sub_00323080);
}
