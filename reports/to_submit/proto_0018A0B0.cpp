// bin: proto
// va: 0x0018A0B0
// what: 
// tool: the portal's starter code (no AI)

// sub_0018A0B0 (Proto 0x0018A0B0, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0016D4C0(int);
};

extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_0018A0B0(int a1, int a2, int a3)
{
    int r_eax;

    r_eax = 0;
    r_eax |= -1;
    if (a2 == 3) {
        r_eax = a3;
        r_eax = sub_002C96FE(*(int*)(r_eax + 8));
    }
    ((Object*)a1)->sub_0016D4C0(r_eax);
}
