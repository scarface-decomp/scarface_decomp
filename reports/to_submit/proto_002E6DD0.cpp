// bin: proto
// va: 0x002E6DD0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6DD0 (Proto 0x002E6DD0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC540(int);
};

extern "C" char DAT_003942E0[];
extern "C" char DAT_00394364[];
extern "C" char DAT_0040D048[];
extern "C" int DAT_0045DE1C;
extern "C" int DAT_0045DE24;
extern "C" int DAT_0045DE28;
extern "C" int DAT_0045DE2C;
extern "C" char sub_000CB610[];
extern "C" char sub_002F35E0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E6DD0(void)
{
    ((Object*)(int)&DAT_0045DE1C)->sub_001FC540((int)DAT_00394364);
    DAT_0045DE1C = (int)DAT_003942E0;
    DAT_0045DE24 = (int)DAT_0040D048;
    DAT_0045DE28 = 11;
    DAT_0045DE2C = (int)sub_000CB610;
    sub_002C8EB3((int)sub_002F35E0);
}
