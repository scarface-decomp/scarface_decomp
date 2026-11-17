// bin: xb
// va: 0x00247BD0
// tool: the portal's starter code (no AI)
// core::ControllerXBox::vfunc_22 (0x00247BD0, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00396568(int);

namespace core {

class ControllerXBox
{
public:
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
    virtual void vfunc_22(int a1);
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

void ControllerXBox::vfunc_22(int a1)
{
    int t1;

    t1 = m_Field08;
    if (m_Field08) {
        sub_00396568(t1);
        m_Field08 = a1;
        return;
    }
    m_Field08 = a1;
}

}
