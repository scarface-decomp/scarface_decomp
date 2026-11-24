// bin: proto
// va: 0x002E4430
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4430 (Proto 0x002E4430, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC3F0(int);
};

extern "C" char DAT_00387DE0[];
extern "C" char DAT_00388254[];
extern "C" int DAT_0045A0D4;
extern "C" int DAT_0045A0DC;
extern "C" char sub_000D7CC0[];
extern "C" char sub_002F1740[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E4430(void)
{
    ((Object*)(int)&DAT_0045A0D4)->sub_001FC3F0((int)DAT_00387DE0);
    DAT_0045A0D4 = (int)DAT_00388254;
    DAT_0045A0DC = (int)sub_000D7CC0;
    sub_002C8EB3((int)sub_002F1740);
}
