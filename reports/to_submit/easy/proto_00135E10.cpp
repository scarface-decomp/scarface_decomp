// bin: proto
// va: 0x00135E10
// tool: the portal's starter code (no AI)
// BlendCamera::vfunc_05 (0x00135E10, 84 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field84
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(float, int);
    virtual void vfunc_08();
    virtual void vfunc_09(int);
    virtual void vfunc_10();
    virtual void vfunc_11(int);
};

extern "C" float DAT_0037F534;
extern "C" void __stdcall sub_00028C40(int);

class BlendCamera
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    char m_pad04[0x74];
    float m_Field78; // +0x78
    int m_Field7C; // +0x7C
    int m_Field80; // +0x80
    Field84* m_Field84; // +0x84
};

void BlendCamera::vfunc_05(int a1)
{
    sub_00028C40(a1);
    m_Field84->vfunc_07(m_Field78 * DAT_0037F534, *(int*)((int)m_Field84 + 20));
    m_Field84->vfunc_09(m_Field7C);
    a1 = m_Field80;
    m_Field84->vfunc_11(a1);
}
