// bin: proto
// va: 0x002E42A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E42A0 (Proto 0x002E42A0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC540(int);
};

extern "C" char DAT_00387C4C[];
extern "C" char DAT_00387C78[];
extern "C" char DAT_00401D68[];
extern "C" int DAT_00459FF8;
extern "C" int DAT_0045A000;
extern "C" int DAT_0045A004;
extern "C" int DAT_0045A008;
extern "C" char sub_000D7720[];
extern "C" char sub_002F16A0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E42A0(void)
{
    ((Object*)(int)&DAT_00459FF8)->sub_001FC540((int)DAT_00387C78);
    DAT_00459FF8 = (int)DAT_00387C4C;
    DAT_0045A000 = (int)DAT_00401D68;
    DAT_0045A004 = 4;
    DAT_0045A008 = (int)sub_000D7720;
    sub_002C8EB3((int)sub_002F16A0);
}
