// bin: xb
// va: 0x00277E00
// tool: the portal's starter code (no AI)
// pure3d::PolySkin::vfunc_24 (0x00277E00, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

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
    virtual void vfunc_10(int);
};

namespace pure3d {

class PolySkin
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
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24(int a1);
    char m_pad04[0x40];
    int m_Field44; // +0x44
    int m_Field48; // +0x48
};

void PolySkin::vfunc_24(int a1)
{
    int r_ebx, r_esi, t1;

    t1 = (m_Field48 - m_Field44) >> 4;
    if (((m_Field48 - m_Field44) >> 4) > 0) {
        r_esi = 0;
        r_ebx = t1;
        do {
            ((Object*)*(int*)(r_esi + m_Field44))->vfunc_10(a1);
            r_esi += 16;
            r_ebx -= 1;
        } while (r_ebx);
    }
}

}
