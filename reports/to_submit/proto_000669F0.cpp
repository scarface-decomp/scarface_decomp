// bin: proto
// va: 0x000669F0
// what: 
// tool: the portal's starter code (no AI)

// sub_000669F0 (Proto 0x000669F0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000684D0(int);
};

extern "C" int DAT_0044F588;

void __cdecl sub_000669F0(int a1, int a2, int a3)
{
    ((Object*)DAT_0044F588 + 12)->sub_000684D0(*(int*)(a3 + 4));
}
