// bin: proto
// va: 0x000BAD50
// what: 
// tool: the portal's starter code (no AI)

// sub_000BAD50 (Proto 0x000BAD50, 27 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000B93B0(int);
};

extern "C" int __cdecl sub_0008E600(int);

void __cdecl sub_000BAD50(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_000B93B0(sub_0008E600(*(int*)(a3 + 8)));
}
