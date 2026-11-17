// bin: proto
// va: 0x00190A40
// tool: the portal's starter code (no AI)
// sub_00190A40 (0x00190A40, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
};

class Class_00190A40
{
public:
    void sub_00190A40();
    char m_pad00[0x48];
    int m_Field48; // +0x48
    int m_Field4C; // +0x4C
};

void Class_00190A40::sub_00190A40()
{
    int r_ebx, r_edi, t1, t2;

    t1 = m_Field48;
    if (m_Field48) {
        r_ebx = *(int*)(t1 + 4);
        r_edi = *(int*)t1;
        if (r_edi != r_ebx) {
            do {
                t2 = *(int*)r_edi;
                if (!*(bool*)(*(int*)r_edi + 34)) {
                    ((Object*)t2)->vfunc_02();
                    *(unsigned short*)(t2 + 32) = *(unsigned short*)(m_Field4C + 28);
                    ((Object*)t2)->vfunc_11();
                }
                r_edi += 4;
            } while (r_edi != r_ebx);
        }
    }
}
