// bin: proto
// va: 0x002ED2D0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ED2D0 (Proto 0x002ED2D0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC460(int);
};

extern "C" char DAT_003ACE68[];
extern "C" char DAT_003ACE80[];
extern "C" int DAT_004638B0;
extern "C" int DAT_004638B8;
extern "C" char sub_001F8320[];
extern "C" char sub_002F7830[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002ED2D0(void)
{
    ((Object*)(int)&DAT_004638B0)->sub_001FC460((int)DAT_003ACE80);
    DAT_004638B0 = (int)DAT_003ACE68;
    DAT_004638B8 = (int)sub_001F8320;
    sub_002C8EB3((int)sub_002F7830);
}
