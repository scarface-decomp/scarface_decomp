// bin: xb
// va: 0x001F87F0
// tool: the portal's starter code (no AI)
// sub_001F87F0 (0x001F87F0, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_001F87F0
{
public:
    void sub_001F87F0(int a1);
};

void Class_001F87F0::sub_001F87F0(int a1)
{
    int r_edi, r_esi;

    r_esi = 0;
    r_edi = (int)this;
L_10:
    if (sub_0002AC90(*(int*)r_edi)) {
        if (!*(bool*)(r_edi + 13)) goto L_36;
        *(int*)(a1 + (r_esi * 4)) = sub_0002AC90(*(int*)r_edi);
        goto L_3D;
    }
L_36:
    *(int*)(a1 + (r_esi * 4)) = 0;
L_3D:
    r_esi += 1;
    r_edi += 16;
    if (r_esi < 8) goto L_10;
}
