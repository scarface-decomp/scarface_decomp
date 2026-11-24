// bin: proto
// va: 0x002E3F10
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E3F10 (Proto 0x002E3F10, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC460(int);
};

extern "C" char DAT_00385C28[];
extern "C" char DAT_00385E5C[];
extern "C" int DAT_00459E6C;
extern "C" int DAT_00459E74;
extern "C" char sub_000CB7C0[];
extern "C" char sub_002F1670[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E3F10(void)
{
    ((Object*)(int)&DAT_00459E6C)->sub_001FC460((int)DAT_00385E5C);
    DAT_00459E6C = (int)DAT_00385C28;
    DAT_00459E74 = (int)sub_000CB7C0;
    sub_002C8EB3((int)sub_002F1670);
}
