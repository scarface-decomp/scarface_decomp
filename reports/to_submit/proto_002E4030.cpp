// bin: proto
// va: 0x002E4030
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4030 (Proto 0x002E4030, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC540(int);
};

extern "C" char DAT_00385CB0[];
extern "C" char DAT_00385EB4[];
extern "C" char DAT_003FFC54[];
extern "C" int DAT_00459EB4;
extern "C" int DAT_00459EBC;
extern "C" int DAT_00459EC0;
extern "C" int DAT_00459EC4;
extern "C" char sub_000CB610[];
extern "C" char sub_002F15F0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E4030(void)
{
    ((Object*)(int)&DAT_00459EB4)->sub_001FC540((int)DAT_00385EB4);
    DAT_00459EB4 = (int)DAT_00385CB0;
    DAT_00459EBC = (int)DAT_003FFC54;
    DAT_00459EC0 = 11;
    DAT_00459EC4 = (int)sub_000CB610;
    sub_002C8EB3((int)sub_002F15F0);
}
