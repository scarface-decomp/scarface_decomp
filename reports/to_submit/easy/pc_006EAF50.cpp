// bin: pc
// va: 0x006EAF50
// tool: the portal's starter code (no AI)
// sub_006EAF50 (0x006EAF50, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
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
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual bool vfunc_24();
};

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
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual bool vfunc_24();
};

class Class_006EAF50
{
public:
    bool sub_006EAF50();
    void sub_006EA9E0();
    void sub_006EABA0();
    char m_pad00[0x8];
    Field08* m_Field08; // +0x08
    bool m_Field0C; // +0x0C
    char m_pad0D[0x3];
    unsigned char m_Field10; // +0x10
};

bool Class_006EAF50::sub_006EAF50()
{
    Field08* t1;

    if (m_Field10) {
        t1 = m_Field08;
        m_Field10 = 0;
        if (!((Object*)(int)t1)->vfunc_24()) {
            sub_006EA9E0();
        }
        if (m_Field08->vfunc_24()) {
            m_Field0C = true;
            sub_006EABA0();
            return m_Field0C;
        }
        m_Field0C = false;
    }
    return m_Field0C;
}
