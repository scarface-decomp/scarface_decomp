// bin: xb
// va: 0x000516C0
// tool: the portal's starter code (no AI)
// sub_000516C0 (0x000516C0, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

class Class_000516C0
{
public:
    void sub_000516C0();
    char m_pad00[0x38];
    int m_Field38; // +0x38
    int m_Field3C; // +0x3C
};

void Class_000516C0::sub_000516C0()
{
    int r_ebx, r_edi, t1, t3;

    r_ebx = 0;
    if (m_Field38 > 0) {
        r_edi = 0;
        do {
            t1 = *(int*)(r_edi + m_Field3C + 32);
            if (*(int*)(r_edi + m_Field3C + 32)) {
                ((Object*)t1)->vfunc_00(1);
            }
            *(int*)(r_edi + m_Field3C + 32) = 0;
            *(int*)(r_edi + m_Field3C + 20) = 3;
            *(int*)(r_edi + m_Field3C) = 0;
            t3 = m_Field38;
            r_ebx += 1;
            r_edi += 36;
        } while (r_ebx < t3);
    }
}
