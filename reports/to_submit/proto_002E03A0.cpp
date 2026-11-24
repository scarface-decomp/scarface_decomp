// bin: proto
// va: 0x002E03A0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E03A0 (Proto 0x002E03A0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC3F0(int);
};

extern "C" char DAT_0037DB90[];
extern "C" char DAT_0037DBC4[];
extern "C" int DAT_00446A00;
extern "C" int DAT_00446A08;
extern "C" char sub_00020660[];
extern "C" char sub_002F0A50[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E03A0(void)
{
    ((Object*)(int)&DAT_00446A00)->sub_001FC3F0((int)DAT_0037DBC4);
    DAT_00446A00 = (int)DAT_0037DB90;
    DAT_00446A08 = (int)sub_00020660;
    sub_002C8EB3((int)sub_002F0A50);
}
