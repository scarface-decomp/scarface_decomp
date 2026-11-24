// bin: proto
// va: 0x001AC7D0
// what: 
// tool: the portal's starter code (no AI)

// sub_001AC7D0 (Proto 0x001AC7D0, 92 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001AF790(int);
    void sub_001AF920(int, int);
};

extern "C" int DAT_00460C24;
extern "C" int __cdecl sub_002014E0(int, int);

void __cdecl sub_001AC7D0(int a1, int a2, int a3)
{
    int r_eax, r_edi, t3;

    r_eax = *(int*)(a3 + 4);
    r_eax = sub_002014E0(r_eax, 0);
    r_eax = ((Object*)DAT_00460C24)->sub_001AF790(r_eax);
    r_edi = r_eax;
    if (a2 > 2) {
        t3 = *(int*)(a3 + 8);
        if (!*(int*)(a3 + 8)) goto L_4C;
        if (!*(unsigned char*)t3) goto L_4C;
        r_eax = sub_002014E0(t3, 0);
        r_eax = ((Object*)DAT_00460C24)->sub_001AF790(r_eax);
    }
L_4C:
    ((Object*)DAT_00460C24)->sub_001AF920(r_edi, r_eax);
}
