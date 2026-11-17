// bin: proto
// va: 0x0018E170
// tool: the portal's starter code (no AI)
// sub_0018E170 (0x0018E170, 45 bytes)
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

extern "C" float DAT_0037CE50;
extern "C" float DAT_003850D4;

class Class_0018E170
{
public:
    void sub_0018E170(float a1, float a2);
    char m_pad00[0x48];
    Field48* m_Field48; // +0x48
};

void Class_0018E170::sub_0018E170(float a1, float a2)
{
    m_Field48->vfunc_14(((a1 / a2) + DAT_0037CE50) * DAT_003850D4);
}
