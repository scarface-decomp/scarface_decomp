// bin: xb
// va: 0x00073500
// tool: the portal's starter code (no AI)
// sub_00073500 (0x00073500, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00099AC0(int);
};

extern "C" void __cdecl sub_00073500(int, int);

void __cdecl sub_00073500(int a1, int a2)
{
    int r_edi, r_esi, t1;

    t1 = *(int*)(a1 + 36);
    if (*(int*)(a1 + 36)) {
        sub_00073500(t1, a2);
    }
    r_edi = *(short*)(a1 + 12);
    r_esi = 0;
    if (r_edi > 0) {
        do {
            ((Object*)a2)->sub_00099AC0((((short)((unsigned short)r_esi)) << 4) + *(int*)(a1 + 4));
            r_esi += 1;
        } while (r_esi < r_edi);
    }
}
