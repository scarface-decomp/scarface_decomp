// bin: proto
// va: 0x002E5E20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5E20 (Proto 0x002E5E20, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000AABF0();
};

extern "C" Object DAT_0045CC20;
extern "C" char sub_002F3040[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E5E20(void)
{
    DAT_0045CC20.sub_000AABF0();
    sub_002C8EB3((int)sub_002F3040);
}
