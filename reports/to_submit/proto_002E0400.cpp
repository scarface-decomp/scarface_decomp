// bin: proto
// va: 0x002E0400
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E0400 (Proto 0x002E0400, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC460(int);
};

extern "C" char DAT_0037DBAC[];
extern "C" char DAT_0037DBE0[];
extern "C" int DAT_00446A18;
extern "C" int DAT_00446A20;
extern "C" char sub_00020670[];
extern "C" char sub_002F0A60[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E0400(void)
{
    ((Object*)(int)&DAT_00446A18)->sub_001FC460((int)DAT_0037DBE0);
    DAT_00446A18 = (int)DAT_0037DBAC;
    DAT_00446A20 = (int)sub_00020670;
    sub_002C8EB3((int)sub_002F0A60);
}
