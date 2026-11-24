// bin: proto
// va: 0x002E1900
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E1900 (Proto 0x002E1900, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008E240(int);
};

extern "C" Object DAT_0044AE4C;
extern "C" char sub_002F11D0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E1900(void)
{
    DAT_0044AE4C.sub_0008E240(-1);
    sub_002C8EB3((int)sub_002F11D0);
}
