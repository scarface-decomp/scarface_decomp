// bin: proto
// va: 0x00101FC0
// what: 
// tool: the portal's starter code (no AI)

// sub_00101FC0 (Proto 0x00101FC0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001023C0(int);
};

extern "C" int DAT_0045BF64;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_00101FC0(int a1, int a2, int a3)
{
    int t1;

    t1 = DAT_0045BF64;
    ((Object*)t1)->sub_001023C0(sub_002014E0(*(int*)(a3 + 4), 0));
}
