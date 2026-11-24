// bin: proto
// va: 0x002E4370
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4370 (Proto 0x002E4370, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC360(int);
};

extern "C" char DAT_00387D90[];
extern "C" char DAT_00387DD4[];
extern "C" int DAT_0045A02C;
extern "C" int DAT_0045A034;
extern "C" char sub_000D7370[];
extern "C" char sub_002F16D0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E4370(void)
{
    ((Object*)(int)&DAT_0045A02C)->sub_001FC360((int)DAT_00387DD4);
    DAT_0045A02C = (int)DAT_00387D90;
    DAT_0045A034 = (int)sub_000D7370;
    sub_002C8EB3((int)sub_002F16D0);
}
