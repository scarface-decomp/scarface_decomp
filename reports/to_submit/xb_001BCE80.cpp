// bin: xb
// va: 0x001BCE80
// what: 
// tool: the portal's starter code (no AI)

// sub_001BCE80 (0x001BCE80, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00192020(int);
};

extern "C" int __cdecl sub_002FC43E(int);

void __cdecl sub_001BCE80(int a1, int a2, int a3)
{
    int r_eax;

    r_eax = 0;
    r_eax |= -1;
    if (a2 == 3) {
        r_eax = a3;
        r_eax = sub_002FC43E(*(int*)(r_eax + 8));
    }
    ((Object*)a1)->sub_00192020(r_eax);
}
