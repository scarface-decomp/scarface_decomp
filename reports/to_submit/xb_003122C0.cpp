// bin: xb
// va: 0x003122C0
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003122C0 (0x003122C0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0023EBB0(int);
};

extern "C" char DAT_0039E560[];
extern "C" char DAT_0039E594[];
extern "C" int DAT_004716D0;
extern "C" int DAT_004716D8;
extern "C" char sub_000DD0D0[];
extern "C" char sub_00322610[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_003122C0(void)
{
    ((Object*)(int)&DAT_004716D0)->sub_0023EBB0((int)DAT_0039E594);
    DAT_004716D0 = (int)DAT_0039E560;
    DAT_004716D8 = (int)sub_000DD0D0;
    sub_002FBBEF((int)sub_00322610);
}
