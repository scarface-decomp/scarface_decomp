// bin: xb
// va: 0x001EEA70
// what: 
// tool: the portal's starter code (no AI)

// sub_001EEA70 (0x001EEA70, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001F34A0(int);
};

extern "C" int __cdecl sub_002FC43E(int);

void __cdecl sub_001EEA70(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_001F34A0(sub_002FC43E(*(int*)(a3 + 8)));
}
