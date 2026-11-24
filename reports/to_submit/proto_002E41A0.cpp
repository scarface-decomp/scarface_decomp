// bin: proto
// va: 0x002E41A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E41A0 (Proto 0x002E41A0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC540(int);
};

extern "C" char DAT_00385D7C[];
extern "C" char DAT_00385F34[];
extern "C" char DAT_003FFCD4[];
extern "C" int DAT_00459F10;
extern "C" int DAT_00459F18;
extern "C" int DAT_00459F1C;
extern "C" int DAT_00459F20;
extern "C" char sub_000CB610[];
extern "C" char sub_002F1660[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E41A0(void)
{
    ((Object*)(int)&DAT_00459F10)->sub_001FC540((int)DAT_00385F34);
    DAT_00459F10 = (int)DAT_00385D7C;
    DAT_00459F18 = (int)DAT_003FFCD4;
    DAT_00459F1C = 5;
    DAT_00459F20 = (int)sub_000CB610;
    sub_002C8EB3((int)sub_002F1660);
}
