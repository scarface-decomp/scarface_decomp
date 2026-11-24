// bin: proto
// va: 0x002E43D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E43D0 (Proto 0x002E43D0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC460(int);
};

extern "C" char DAT_00387E90[];
extern "C" char DAT_00387EA8[];
extern "C" int DAT_0045A0A4;
extern "C" int DAT_0045A0AC;
extern "C" char sub_000D7590[];
extern "C" char sub_002F1710[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E43D0(void)
{
    ((Object*)(int)&DAT_0045A0A4)->sub_001FC460((int)DAT_00387EA8);
    DAT_0045A0A4 = (int)DAT_00387E90;
    DAT_0045A0AC = (int)sub_000D7590;
    sub_002C8EB3((int)sub_002F1710);
}
