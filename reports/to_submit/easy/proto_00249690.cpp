// bin: proto
// va: 0x00249690
// tool: the portal's starter code (no AI)
// pure3d::frontend::TextMenuItem::vfunc_21 (0x00249690, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00206370(int);
};

namespace pure3d { namespace frontend {

class TextMenuItem
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
    char m_pad04[0x28];
    char m_Field2C; // +0x2C
    bool m_Field2D; // +0x2D
    char m_pad2E[0x6];
    int m_Field34; // +0x34
};

void TextMenuItem::vfunc_21()
{
    int r_eax, r_edx;
    bool t1;

    r_edx = m_Field34;
    if (!r_edx) goto L_2C;
    r_eax = *(short*)(r_edx + 80);
    t1 = m_Field2D;
    r_eax -= 1;
    if (t1 & 4) {
        if (r_eax >= 0) goto L_24;
        r_eax += m_Field2C;
    }
    if (r_eax < 0) goto L_2C;
L_24:
    ((Object*)r_edx)->sub_00206370(r_eax);
L_2C:
    ;
}

} }
