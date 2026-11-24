// bin: proto
// va: 0x002E4110
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4110 (Proto 0x002E4110, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC460(int);
};

extern "C" char DAT_00385D44[];
extern "C" char DAT_00385EF8[];
extern "C" int DAT_00459EEC;
extern "C" int DAT_00459EF4;
extern "C" char sub_000CB7C0[];
extern "C" char sub_002F1630[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E4110(void)
{
    ((Object*)(int)&DAT_00459EEC)->sub_001FC460((int)DAT_00385EF8);
    DAT_00459EEC = (int)DAT_00385D44;
    DAT_00459EF4 = (int)sub_000CB7C0;
    sub_002C8EB3((int)sub_002F1630);
}
