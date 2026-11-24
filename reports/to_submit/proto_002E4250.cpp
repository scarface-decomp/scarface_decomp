// bin: proto
// va: 0x002E4250
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4250 (Proto 0x002E4250, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC540(int);
};

extern "C" char DAT_00387C4C[];
extern "C" char DAT_00387C6C[];
extern "C" char DAT_00401D58[];
extern "C" int DAT_00459FE4;
extern "C" int DAT_00459FEC;
extern "C" int DAT_00459FF0;
extern "C" int DAT_00459FF4;
extern "C" char sub_000D71F0[];
extern "C" char sub_002F16C0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E4250(void)
{
    ((Object*)(int)&DAT_00459FE4)->sub_001FC540((int)DAT_00387C6C);
    DAT_00459FE4 = (int)DAT_00387C4C;
    DAT_00459FEC = (int)DAT_00401D58;
    DAT_00459FF0 = 4;
    DAT_00459FF4 = (int)sub_000D71F0;
    sub_002C8EB3((int)sub_002F16C0);
}
