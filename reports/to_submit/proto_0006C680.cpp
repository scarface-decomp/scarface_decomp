// bin: proto
// va: 0x0006C680
// what: 
// tool: the portal's starter code (no AI)

// sub_0006C680 (Proto 0x0006C680, 85 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0006DA70(int, int, int);
extern "C" int __cdecl sub_0006EBB0(int);
extern "C" int __cdecl sub_002C96FE(int);

void __cdecl sub_0006C680(int a1, int a2, int a3)
{
    int r_edi, r_esi;

    r_esi = 0;
    r_edi = 500;
    if (a2 > 2) {
        r_edi = sub_002C96FE(*(int*)(a3 + 8));
    }
    if (a2 > 3) {
        r_esi = sub_002C96FE(*(int*)(a3 + 12));
    }
    sub_0006DA70(sub_0006EBB0(*(int*)(a3 + 4)), r_edi, r_esi);
}
