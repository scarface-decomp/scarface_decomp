// bin: proto
// va: 0x002E5E60
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E5E60 (Proto 0x002E5E60, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00152160();
};

extern "C" Object DAT_0045CC98;
extern "C" char sub_002F3050[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E5E60(void)
{
    DAT_0045CC98.sub_00152160();
    sub_002C8EB3((int)sub_002F3050);
}
