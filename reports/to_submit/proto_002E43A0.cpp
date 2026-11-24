// bin: proto
// va: 0x002E43A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E43A0 (Proto 0x002E43A0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC3F0(int);
};

extern "C" char DAT_00387D74[];
extern "C" char DAT_00387DE0[];
extern "C" int DAT_0045A038;
extern "C" int DAT_0045A040;
extern "C" char sub_000D7CC0[];
extern "C" char sub_002F1700[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E43A0(void)
{
    ((Object*)(int)&DAT_0045A038)->sub_001FC3F0((int)DAT_00387DE0);
    DAT_0045A038 = (int)DAT_00387D74;
    DAT_0045A040 = (int)sub_000D7CC0;
    sub_002C8EB3((int)sub_002F1700);
}
