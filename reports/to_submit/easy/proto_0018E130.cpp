// bin: proto
// va: 0x0018E130
// tool: the portal's starter code (no AI)
// sub_0018E130 (0x0018E130, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field48
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
    virtual void vfunc_14(float);
};

extern "C" float DAT_00393980;

class Class_0018E130
{
public:
    void sub_0018E130(int a1);
    char m_pad00[0x48];
    Field48* m_Field48; // +0x48
    int m_Field4C; // +0x4C
    short m_Field50; // +0x50
};

void Class_0018E130::sub_0018E130(int a1)
{
    m_Field48->vfunc_14(((float)a1) / (((float)m_Field50) * DAT_00393980));
    m_Field4C = a1;
}
