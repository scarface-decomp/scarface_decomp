// bin: proto
// va: 0x000BAC90
// what: 
// tool: the portal's starter code (no AI)

// sub_000BAC90 (Proto 0x000BAC90, 74 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000BA1F0(int, int, int);
};

extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_000BAC90(int a1, int a2, int a3)
{
    int r_edi, r_esi;

    r_edi = 0;
    r_esi = 0;
    if (a2 >= 4) {
        r_edi = sub_002C96FE(*(int*)(a3 + 12));
    }
    if (a2 >= 5) {
        r_esi = sub_002C96FE(*(int*)(a3 + 16));
    }
    ((Object*)a1)->sub_000BA1F0(*(int*)(a3 + 8), r_edi, r_esi);
}
