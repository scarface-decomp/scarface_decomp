// bin: xb
// va: 0x003193E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003193E0 (0x003193E0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000EB3F0(int, int, int);
};

extern "C" Object DAT_0048BFEC;
extern "C" char sub_00184080[];

void __cdecl sub_003193E0(void)
{
    DAT_0048BFEC.sub_000EB3F0(40, (int)sub_00184080, 0);
}
