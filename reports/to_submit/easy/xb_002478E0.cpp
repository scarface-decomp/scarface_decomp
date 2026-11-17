// bin: xb
// va: 0x002478E0
// tool: the portal's starter code (no AI)
// core::ControllerSystemXBox::vfunc_08 (0x002478E0, 74 bytes)
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
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19(int);
};

extern "C" int __cdecl sub_00242A50(void);

namespace core {

class ControllerSystemXBox
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
    virtual void vfunc_08(int a1, int a2);
    char m_pad04[0x10];
    int m_Field14; // +0x14
    char m_pad18[0x8];
    int m_Field20; // +0x20
};

void ControllerSystemXBox::vfunc_08(int a1, int a2)
{
    int r_ebx, r_esi;

    m_Field14 = a2 - a1;
    r_esi = (int)(&m_Field20);
    r_ebx = 4;
    do {
        if (*(bool*)(r_esi + 1182)) {
            ((Object*)r_esi)->vfunc_19(sub_00242A50() + m_Field14);
        }
        r_esi += 1184;
        r_ebx -= 1;
    } while (r_ebx);
}

}
