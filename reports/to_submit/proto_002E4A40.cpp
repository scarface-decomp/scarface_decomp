// bin: proto
// va: 0x002E4A40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4A40 (Proto 0x002E4A40, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D8CC0(int, int, int, int, int, int, int, int, int, int);
};

extern "C" char DAT_0038B388[];
extern "C" Object DAT_0045BD20;
extern "C" char sub_000FC170[];

void __cdecl sub_002E4A40(void)
{
    DAT_0045BD20.sub_000D8CC0(39, 27, 23, 64, 10, (int)DAT_0038B388, (int)sub_000FC170, 64, 0, 0);
}
