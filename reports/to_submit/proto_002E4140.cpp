// bin: proto
// va: 0x002E4140
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4140 (Proto 0x002E4140, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC460(int);
};

extern "C" char DAT_00385D28[];
extern "C" char DAT_00385F10[];
extern "C" int DAT_00459EF8;
extern "C" int DAT_00459F00;
extern "C" char sub_000CB7C0[];
extern "C" char sub_002F1640[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E4140(void)
{
    ((Object*)(int)&DAT_00459EF8)->sub_001FC460((int)DAT_00385F10);
    DAT_00459EF8 = (int)DAT_00385D28;
    DAT_00459F00 = (int)sub_000CB7C0;
    sub_002C8EB3((int)sub_002F1640);
}
