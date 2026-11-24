// bin: proto
// va: 0x002ED300
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ED300 (Proto 0x002ED300, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC460(int);
};

extern "C" char DAT_003ACE68[];
extern "C" char DAT_003ACE8C[];
extern "C" int DAT_004638A4;
extern "C" int DAT_004638AC;
extern "C" char sub_001F8340[];
extern "C" char sub_002F7820[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002ED300(void)
{
    ((Object*)(int)&DAT_004638A4)->sub_001FC460((int)DAT_003ACE8C);
    DAT_004638A4 = (int)DAT_003ACE68;
    DAT_004638AC = (int)sub_001F8340;
    sub_002C8EB3((int)sub_002F7820);
}
