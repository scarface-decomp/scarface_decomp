// bin: proto
// va: 0x002E4400
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4400 (Proto 0x002E4400, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FC360(int);
};

extern "C" char DAT_00388238[];
extern "C" char DAT_0038826C[];
extern "C" int DAT_0045A0C8;
extern "C" int DAT_0045A0D0;
extern "C" char sub_00163370[];
extern "C" char sub_002F1730[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E4400(void)
{
    ((Object*)(int)&DAT_0045A0C8)->sub_001FC360((int)DAT_0038826C);
    DAT_0045A0C8 = (int)DAT_00388238;
    DAT_0045A0D0 = (int)sub_00163370;
    sub_002C8EB3((int)sub_002F1730);
}
