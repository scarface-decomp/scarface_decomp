// bin: pc
// va: 0x006DE620
// what: 
// tool: the portal's starter code (no AI)

// core::ControllerSystemDirectInput::vfunc_09 (PC 0x006DE620, 44 bytes)
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
    virtual void vfunc_19(int, int);
};

namespace core {

class ControllerSystemDirectInput
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
    virtual void vfunc_09(int a1);
    char m_pad04[0x14];
    int m_Field18; // +0x18
    char m_pad1C[0xC];
    int m_Field28; // +0x28
};

void ControllerSystemDirectInput::vfunc_09(int a1)
{
    int r_ebx, r_esi;

    r_esi = m_Field28;
    if (r_esi) {
        r_ebx = a1;
        do {
            ((Object*)r_esi)->vfunc_19(r_ebx, m_Field18);
            r_esi = *(int*)(r_esi + 640);
        } while (r_esi);
    }
}

}
