// bin: proto
// va: 0x002E4460
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4460 (Proto 0x002E4460, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC360(int);
};

extern "C" char DAT_00388238[];
extern "C" char DAT_00388278[];
extern "C" int DAT_0045A0E0;
extern "C" int DAT_0045A0E8;
extern "C" char sub_000D5F80[];
extern "C" char sub_002F1720[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E4460(void)
{
    ((Object*)(int)&DAT_0045A0E0)->sub_001FC360((int)DAT_00388278);
    DAT_0045A0E0 = (int)DAT_00388238;
    DAT_0045A0E8 = (int)sub_000D5F80;
    sub_002C8EB3((int)sub_002F1720);
}
