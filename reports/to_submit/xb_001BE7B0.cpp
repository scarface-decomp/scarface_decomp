// bin: xb
// va: 0x001BE7B0
// what: 
// tool: the portal's starter code (no AI)

// sub_001BE7B0 (0x001BE7B0, 98 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00195830(int);
    void sub_001A2EA0(int);
    void sub_001A2EE0(int);
};

extern "C" int DAT_0048C23C;
extern "C" int __cdecl sub_002FC43E(int);

void __cdecl sub_001BE7B0(int a1, int a2, int a3)
{
    int r_esi;

    r_esi = ((Object*)DAT_0048C23C)->sub_00195830(18);
    if (sub_002FC43E(*(int*)(a3 + 12)) == 2) {
        r_esi = ((Object*)DAT_0048C23C)->sub_00195830(19);
    }
    if (r_esi) {
        ((Object*)r_esi)->sub_001A2EE0(sub_002FC43E(*(int*)(a3 + 4)));
        if (a2 <= 3) goto L_5F;
        ((Object*)r_esi)->sub_001A2EA0(*(int*)(a3 + 8));
    }
L_5F:
    ;
}
