// bin: xb
// va: 0x001D7390
// what: 
// tool: the portal's starter code (no AI)

// sub_001D7390 (0x001D7390, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001D8540(int);
};

extern "C" int __cdecl sub_002FC43E(int);

void __cdecl sub_001D7390(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_001D8540(sub_002FC43E(*(int*)(a3 + 8)));
}
