// bin: proto
// va: 0x002E30E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E30E0 (Proto 0x002E30E0, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008E240(int);
};

extern "C" Object DAT_004541BC;
extern "C" char sub_002F14E0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E30E0(void)
{
    DAT_004541BC.sub_0008E240(-1);
    sub_002C8EB3((int)sub_002F14E0);
}
