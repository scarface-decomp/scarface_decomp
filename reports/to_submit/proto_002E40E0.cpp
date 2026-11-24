// bin: proto
// va: 0x002E40E0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E40E0 (Proto 0x002E40E0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC460(int);
};

extern "C" char DAT_00385D0C[];
extern "C" char DAT_00385EE4[];
extern "C" int DAT_00459EE0;
extern "C" int DAT_00459EE8;
extern "C" char sub_000CB7C0[];
extern "C" char sub_002F1620[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E40E0(void)
{
    ((Object*)(int)&DAT_00459EE0)->sub_001FC460((int)DAT_00385EE4);
    DAT_00459EE0 = (int)DAT_00385D0C;
    DAT_00459EE8 = (int)sub_000CB7C0;
    sub_002C8EB3((int)sub_002F1620);
}
