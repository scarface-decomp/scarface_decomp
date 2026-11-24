// bin: proto
// va: 0x002E6E20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6E20 (Proto 0x002E6E20, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC540(int);
};

extern "C" char DAT_00394304[];
extern "C" char DAT_0039436C[];
extern "C" char DAT_003FF6C8[];
extern "C" int DAT_003FF728;
extern "C" int DAT_0045DE30;
extern "C" int DAT_0045DE38;
extern "C" int DAT_0045DE3C;
extern "C" int DAT_0045DE40;
extern "C" char sub_000CB610[];
extern "C" char sub_002F35C0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E6E20(void)
{
    int t1;

    t1 = DAT_003FF728;
    ((Object*)(int)&DAT_0045DE30)->sub_001FC540((int)DAT_0039436C);
    DAT_0045DE30 = (int)DAT_00394304;
    DAT_0045DE38 = (int)DAT_003FF6C8;
    DAT_0045DE3C = t1;
    DAT_0045DE40 = (int)sub_000CB610;
    sub_002C8EB3((int)sub_002F35C0);
}
