// bin: proto
// va: 0x001F0BA0
// what: 
// tool: the portal's starter code (no AI)

// sub_001F0BA0 (Proto 0x001F0BA0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00029A80(int, int, int);
};

extern "C" char DAT_0037CFE0[];
extern "C" char DAT_003AC528[];

void __cdecl sub_001F0BA0(int a1)
{
    ((Object*)a1)->sub_00029A80((int)DAT_003AC528, 0, (int)DAT_0037CFE0);
}
