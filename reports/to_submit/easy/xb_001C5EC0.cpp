// bin: xb
// va: 0x001C5EC0
// tool: the portal's starter code (no AI)
// sub_001C5EC0 (0x001C5EC0, 57 bytes)
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
};

class Class_001C5EC0
{
public:
    void sub_001C5EC0();
    char m_pad00[0x48];
    int m_Field48; // +0x48
    int m_Field4C; // +0x4C
};

void Class_001C5EC0::sub_001C5EC0()
{
    int r_edi, r_esi, t1, t2;

    t1 = m_Field48;
    if (m_Field48) {
        r_esi = *(int*)t1;
        r_edi = *(int*)(t1 + 4);
        if (r_esi != r_edi) {
            do {
                t2 = *(int*)r_esi;
                if (!*(bool*)(*(int*)r_esi + 34)) {
                    *(unsigned short*)(t2 + 32) = *(unsigned short*)(m_Field4C + 28);
                    ((Object*)t2)->vfunc_10();
                }
                r_esi += 4;
            } while (r_esi != r_edi);
        }
    }
}
