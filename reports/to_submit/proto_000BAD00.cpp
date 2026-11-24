// bin: proto
// va: 0x000BAD00
// what: 
// tool: the portal's starter code (no AI)

// sub_000BAD00 (Proto 0x000BAD00, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000BA150(int);
};

void __cdecl sub_000BAD00(int a1, int a2, int a3)
{
    ((Object*)a1)->sub_000BA150(*(int*)(a3 + 8));
}
