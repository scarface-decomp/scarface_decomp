// bin: proto
// va: 0x001C4960
// tool: the portal's starter code (no AI)
// WeaponTemplate::vfunc_05 (0x001C4960, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_004616C0[];
extern "C" void __stdcall sub_00028C40(int);

class WeaponTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    char m_pad04[0x20];
    int m_Field24; // +0x24
    char m_pad28[0x68];
    int m_Field90; // +0x90
    float m_Field94; // +0x94
};

void WeaponTemplate::vfunc_05(int a1)
{
    sub_00028C40(a1);
    DAT_004616C0[m_Field24] = (int)this;
    if (0.0f > m_Field94) {
        *(int*)((char*)this + 0x94) = m_Field90;
    }
}
