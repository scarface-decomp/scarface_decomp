// bin: proto
// va: 0x002E3FE0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3FE0 (Proto 0x002E3FE0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC540(int);
};

extern "C" char DAT_00385C8C[];
extern "C" char DAT_00385E9C[];
extern "C" char DAT_003FFC40[];
extern "C" int DAT_00459EA0;
extern "C" int DAT_00459EA8;
extern "C" int DAT_00459EAC;
extern "C" int DAT_00459EB0;
extern "C" char sub_000CB610[];
extern "C" char sub_002F15E0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E3FE0(void)
{
    ((Object*)(int)&DAT_00459EA0)->sub_001FC540((int)DAT_00385E9C);
    DAT_00459EA0 = (int)DAT_00385C8C;
    DAT_00459EA8 = (int)DAT_003FFC40;
    DAT_00459EAC = 4;
    DAT_00459EB0 = (int)sub_000CB610;
    sub_002C8EB3((int)sub_002F15E0);
}
