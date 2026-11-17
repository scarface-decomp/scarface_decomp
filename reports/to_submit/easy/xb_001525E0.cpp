// bin: xb
// va: 0x001525E0
// tool: the portal's starter code (no AI)
// BlendCamera::vfunc_04 (0x001525E0, 81 bytes)
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

extern "C" float DAT_003A00FC;
extern "C" void __stdcall sub_0002B700(int);

class BlendCamera
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    char m_pad04[0x70];
    float m_Field74; // +0x74
    int m_Field78; // +0x78
    int m_Field7C; // +0x7C
    char m_pad80[0x4];
    Field84* m_Field84; // +0x84
};

void BlendCamera::vfunc_04(int a1)
{
    sub_0002B700(a1);
    m_Field84->vfunc_07(m_Field74 * DAT_003A00FC, *(int*)((int)m_Field84 + 20));
    m_Field84->vfunc_09(m_Field78);
    a1 = m_Field7C;
    m_Field84->vfunc_11(a1);
}
