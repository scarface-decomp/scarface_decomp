// bin: proto
// va: 0x002E03D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E03D0 (Proto 0x002E03D0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC3F0(int);
};

extern "C" char DAT_0037DB90[];
extern "C" char DAT_0037DBD0[];
extern "C" int DAT_00446A0C;
extern "C" int DAT_00446A14;
extern "C" char sub_000D7CC0[];
extern "C" char sub_002F0A40[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E03D0(void)
{
    ((Object*)(int)&DAT_00446A0C)->sub_001FC3F0((int)DAT_0037DBD0);
    DAT_00446A0C = (int)DAT_0037DB90;
    DAT_00446A14 = (int)sub_000D7CC0;
    sub_002C8EB3((int)sub_002F0A40);
}
