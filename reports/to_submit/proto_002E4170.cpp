// bin: proto
// va: 0x002E4170
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4170 (Proto 0x002E4170, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC460(int);
};

extern "C" char DAT_00385D60[];
extern "C" char DAT_00385F20[];
extern "C" int DAT_00459F04;
extern "C" int DAT_00459F0C;
extern "C" char sub_0001C290[];
extern "C" char sub_002F1650[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E4170(void)
{
    ((Object*)(int)&DAT_00459F04)->sub_001FC460((int)DAT_00385F20);
    DAT_00459F04 = (int)DAT_00385D60;
    DAT_00459F0C = (int)sub_0001C290;
    sub_002C8EB3((int)sub_002F1650);
}
