// bin: proto
// va: 0x002E6E70
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E6E70 (Proto 0x002E6E70, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC540(int);
};

extern "C" char DAT_00394328[];
extern "C" char DAT_0039436C[];
extern "C" char DAT_003FF6C8[];
extern "C" int DAT_003FF728;
extern "C" int DAT_0045DE44;
extern "C" int DAT_0045DE4C;
extern "C" int DAT_0045DE50;
extern "C" int DAT_0045DE54;
extern "C" char sub_000CB610[];
extern "C" char sub_002F35D0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E6E70(void)
{
    int t1;

    t1 = DAT_003FF728;
    ((Object*)(int)&DAT_0045DE44)->sub_001FC540((int)DAT_0039436C);
    DAT_0045DE44 = (int)DAT_00394328;
    DAT_0045DE4C = (int)DAT_003FF6C8;
    DAT_0045DE50 = t1;
    DAT_0045DE54 = (int)sub_000CB610;
    sub_002C8EB3((int)sub_002F35D0);
}
