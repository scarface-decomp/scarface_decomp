// bin: proto
// va: 0x00068EE0
// tool: the portal's starter code (no AI)
// sub_00068EE0 (0x00068EE0, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008E500(int);
};

extern "C" void __cdecl sub_00068EE0(int, int);

void __cdecl sub_00068EE0(int a1, int a2)
{
    int r_edi, r_esi, t1;

    t1 = *(int*)(a1 + 40);
    if (*(int*)(a1 + 40)) {
        sub_00068EE0(t1, a2);
    }
    r_edi = *(short*)(a1 + 12);
    r_esi = 0;
    if (r_edi > 0) {
        do {
            ((Object*)a2)->sub_0008E500((((short)((unsigned short)r_esi)) << 4) + *(int*)(a1 + 4));
            r_esi += 1;
        } while (r_esi < r_edi);
    }
}
