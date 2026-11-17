// bin: xb
// va: 0x001C25C0
// tool: the portal's starter code (no AI)
// sub_001C25C0 (0x001C25C0, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field6C
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

extern "C" float DAT_0039D664;
extern "C" float DAT_003D1058;

class Class_001C25C0
{
public:
    void sub_001C25C0(float a1, float a2);
    char m_pad00[0x6C];
    Field6C* m_Field6C; // +0x6C
};

void Class_001C25C0::sub_001C25C0(float a1, float a2)
{
    m_Field6C->vfunc_14(((a1 / a2) + DAT_0039D664) * DAT_003D1058);
}
