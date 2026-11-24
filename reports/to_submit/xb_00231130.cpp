// bin: xb
// va: 0x00231130
// what: 
// tool: the portal's starter code (no AI)

// sub_00231130 (0x00231130, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002320A0(int);
};

extern "C" int DAT_004928FC;

void __cdecl sub_00231130(int a1, int a2, int a3)
{
    ((Object*)DAT_004928FC)->sub_002320A0(*(int*)(a3 + 4));
}
