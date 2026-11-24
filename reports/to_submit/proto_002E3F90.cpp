// bin: proto
// va: 0x002E3F90
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3F90 (Proto 0x002E3F90, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC540(int);
};

extern "C" char DAT_00385C68[];
extern "C" char DAT_00385E84[];
extern "C" char DAT_003FFC24[];
extern "C" int DAT_00459E8C;
extern "C" int DAT_00459E94;
extern "C" int DAT_00459E98;
extern "C" int DAT_00459E9C;
extern "C" char sub_000CB610[];
extern "C" char sub_002F15D0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E3F90(void)
{
    ((Object*)(int)&DAT_00459E8C)->sub_001FC540((int)DAT_00385E84);
    DAT_00459E8C = (int)DAT_00385C68;
    DAT_00459E94 = (int)DAT_003FFC24;
    DAT_00459E98 = 6;
    DAT_00459E9C = (int)sub_000CB610;
    sub_002C8EB3((int)sub_002F15D0);
}
