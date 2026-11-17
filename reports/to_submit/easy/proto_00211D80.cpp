// bin: proto
// va: 0x00211D80
// tool: the portal's starter code (no AI)
// sub_00211D80 (0x00211D80, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct FieldE8
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
};

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
};

extern "C" int DAT_00464C98;

class Class_00211D80
{
public:
    void sub_00211D80(bool a1);
    char m_pad00[0xE8];
    FieldE8* m_FieldE8; // +0xE8
    char m_padEC[0x8];
    bool m_FieldF4; // +0xF4
};

void Class_00211D80::sub_00211D80(bool a1)
{
    ((Object*)DAT_00464C98)->vfunc_05();
    m_FieldF4 = false;
    if (a1) {
        m_FieldE8->vfunc_14();
    }
}
