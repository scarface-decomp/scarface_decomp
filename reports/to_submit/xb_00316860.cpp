// bin: xb
// va: 0x00316860
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00316860 (0x00316860, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00241E00();
};

extern "C" Object DAT_00489670;
extern "C" int DAT_0048968C;
extern "C" char sub_00323390[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00316860(void)
{
    DAT_00489670.sub_00241E00();
    DAT_0048968C = 32;
    sub_002FBBEF((int)sub_00323390);
}
