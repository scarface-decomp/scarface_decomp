// bin: xb
// va: 0x00317BF0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00317BF0 (0x00317BF0, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0006F830(int, int, int, int, int, int);
};

extern "C" char DAT_0042F11C[];
extern "C" char DAT_0042F12C[];
extern "C" Object DAT_0048A768;
extern "C" char sub_0015D3C0[];

void __cdecl sub_00317BF0(void)
{
    DAT_0048A768.sub_0006F830((int)DAT_0042F12C, (int)DAT_0042F11C, (int)sub_0015D3C0, 0, 3, 3);
}
