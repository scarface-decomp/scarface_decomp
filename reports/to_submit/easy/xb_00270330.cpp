// bin: xb
// va: 0x00270330
// tool: the portal's starter code (no AI)
// sub_00270330 (0x00270330, 87 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    void sub_002702D0(int);
};

class Class_00270330
{
public:
    int sub_00270330(int a1, int a2, int a3, int a4);
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    char m_pad10[0xC];
    int m_Field1C; // +0x1C
};

int Class_00270330::sub_00270330(int a1, int a2, int a3, int a4)
{
    int r_eax, r_edi, r_edx;

    r_edi = a1;
    ((Object*)a1)->sub_002702D0(a2);
    r_eax = 0;
    if (a2 > 0) {
        r_edx = a4;
        r_edx <<= 2;
        do {
            *(int*)(*(int*)r_edi + (r_eax * 8)) = m_Field1C + ((*(int*)(a3 + (r_eax * 4)) + (*(int*)(a3 + (r_eax * 4)) * 2)) * 8);
            *(int*)(*(int*)r_edi + (r_eax * 8) + 4) = *(int*)(r_edx + *(int*)(m_Field0C + 12));
            r_eax += 1;
            r_edx += 4;
        } while (r_eax < a2);
    }
    return r_eax;
}
