// bin: proto
// va: 0x000AC840
// tool: the portal's starter code (no AI)
// sub_000AC840 (0x000AC840, 88 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01(int);
};

extern "C" void __cdecl sub_00015590(int);

class Class_000AC840
{
public:
    void sub_000AC840();
    char m_pad00[0x4];
    int m_Field04; // +0x04
    char m_pad08[0x4];
    int m_Field0C; // +0x0C
};

void Class_000AC840::sub_000AC840()
{
    int r_ebx, r_esi, t1, t3, t5;

    t1 = m_Field04;
    if (m_Field04) {
        sub_00015590(t1);
        m_Field04 = 0;
    }
    r_esi = (int)(&m_Field0C);
    r_ebx = 30;
    do {
        t3 = *(int*)r_esi;
        if (*(int*)r_esi) {
            ((Object*)t3)->vfunc_01(1);
            *(int*)r_esi = 0;
        }
        r_esi += 4;
        r_ebx -= 1;
    } while (r_ebx);
    t5 = m_Field04;
    if (m_Field04) {
        sub_00015590(t5);
        m_Field04 = 0;
    }
}
