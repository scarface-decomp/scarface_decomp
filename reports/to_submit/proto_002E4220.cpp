// bin: proto
// va: 0x002E4220
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4220 (Proto 0x002E4220, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC460(int);
};

extern "C" char DAT_0038540C[];
extern "C" char DAT_00387C30[];
extern "C" int DAT_00459FD8;
extern "C" int DAT_00459FE0;
extern "C" char sub_000D71D0[];
extern "C" char sub_002F16B0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E4220(void)
{
    ((Object*)(int)&DAT_00459FD8)->sub_001FC460((int)DAT_0038540C);
    DAT_00459FD8 = (int)DAT_00387C30;
    DAT_00459FE0 = (int)sub_000D71D0;
    sub_002C8EB3((int)sub_002F16B0);
}
