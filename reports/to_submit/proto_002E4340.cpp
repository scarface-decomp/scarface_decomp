// bin: proto
// va: 0x002E4340
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4340 (Proto 0x002E4340, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC360(int);
};

extern "C" char DAT_00387D90[];
extern "C" char DAT_00387DB8[];
extern "C" int DAT_0045A020;
extern "C" int DAT_0045A028;
extern "C" char sub_000D7340[];
extern "C" char sub_002F16F0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E4340(void)
{
    ((Object*)(int)&DAT_0045A020)->sub_001FC360((int)DAT_00387DB8);
    DAT_0045A020 = (int)DAT_00387D90;
    DAT_0045A028 = (int)sub_000D7340;
    sub_002C8EB3((int)sub_002F16F0);
}
