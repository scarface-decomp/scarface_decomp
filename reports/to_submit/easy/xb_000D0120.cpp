// bin: xb
// va: 0x000D0120
// tool: the portal's starter code (no AI)
// sub_000D0120 (0x000D0120, 88 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00244250(int);
};

class Class_000D0120
{
public:
    int sub_000D0120(int a1, int a2);
};

int Class_000D0120::sub_000D0120(int a1, int a2)
{
    int r_eax;

    r_eax = (int)this;
    if (*(int*)(r_eax + 256)) {
        *(int*)a2 = *(int*)(r_eax + 260);
        *(int*)(a2 + 4) = *(int*)(r_eax + 264);
        *(int*)(a2 + 8) = *(int*)(r_eax + 268);
        if (*(int*)(r_eax + 256) != 1) goto L_55;
        r_eax = a1;
        r_eax = ((Object*)a2)->sub_00244250(a1);
        return r_eax;
    }
    r_eax = a2;
    *(float*)r_eax = 0.0f;
    *(float*)(r_eax + 4) = 0.0f;
    *(float*)(r_eax + 8) = 0.0f;
L_55:
    return r_eax;
}
