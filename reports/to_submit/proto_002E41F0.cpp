// bin: proto
// va: 0x002E41F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E41F0 (Proto 0x002E41F0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC4F0(int);
};

extern "C" char DAT_00387490[];
extern "C" char DAT_003874AC[];
extern "C" int DAT_00459F9C;
extern "C" int DAT_00459FA4;
extern "C" char sub_000D5260[];
extern "C" char sub_002F1690[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E41F0(void)
{
    ((Object*)(int)&DAT_00459F9C)->sub_001FC4F0((int)DAT_003874AC);
    DAT_00459F9C = (int)DAT_00387490;
    DAT_00459FA4 = (int)sub_000D5260;
    sub_002C8EB3((int)sub_002F1690);
}
