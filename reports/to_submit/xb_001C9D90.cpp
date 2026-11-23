// bin: xb
// va: 0x001C9D90
// what: 
// tool: the portal's starter code (no AI)

// sub_001C9D90 (0x001C9D90, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001C8E40(int);
};

extern "C" int __cdecl sub_002FC43E(int);

void __cdecl sub_001C9D90(int a1, int a2, int a3)
{
    if (a1) {
        ((Object*)a1)->sub_001C8E40(sub_002FC43E(*(int*)(a3 + 8)));
    }
}
