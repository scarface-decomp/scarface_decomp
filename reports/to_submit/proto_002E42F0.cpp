// bin: proto
// va: 0x002E42F0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E42F0 (Proto 0x002E42F0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC540(int);
};

extern "C" char DAT_00387D50[];
extern "C" char DAT_00387DA8[];
extern "C" char DAT_00401E0C[];
extern "C" int DAT_0045A00C;
extern "C" int DAT_0045A014;
extern "C" int DAT_0045A018;
extern "C" int DAT_0045A01C;
extern "C" char sub_000D7320[];
extern "C" char sub_002F16E0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E42F0(void)
{
    ((Object*)(int)&DAT_0045A00C)->sub_001FC540((int)DAT_00387DA8);
    DAT_0045A00C = (int)DAT_00387D50;
    DAT_0045A014 = (int)DAT_00401E0C;
    DAT_0045A018 = 6;
    DAT_0045A01C = (int)sub_000D7320;
    sub_002C8EB3((int)sub_002F16E0);
}
