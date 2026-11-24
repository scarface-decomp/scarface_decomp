// bin: proto
// va: 0x002E3F40
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3F40 (Proto 0x002E3F40, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC540(int);
};

extern "C" char DAT_00385C44[];
extern "C" char DAT_00385E70[];
extern "C" char DAT_003FFC18[];
extern "C" int DAT_00459E78;
extern "C" int DAT_00459E80;
extern "C" int DAT_00459E84;
extern "C" int DAT_00459E88;
extern "C" char sub_000CB610[];
extern "C" char sub_002F1680[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E3F40(void)
{
    ((Object*)(int)&DAT_00459E78)->sub_001FC540((int)DAT_00385E70);
    DAT_00459E78 = (int)DAT_00385C44;
    DAT_00459E80 = (int)DAT_003FFC18;
    DAT_00459E84 = 2;
    DAT_00459E88 = (int)sub_000CB610;
    sub_002C8EB3((int)sub_002F1680);
}
