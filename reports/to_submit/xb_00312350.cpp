// bin: xb
// va: 0x00312350
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312350 (0x00312350, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000997E0(int);
};

extern "C" Object DAT_00471788;
extern "C" char sub_00322630[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00312350(void)
{
    DAT_00471788.sub_000997E0(-1);
    sub_002FBBEF((int)sub_00322630);
}
