// bin: proto
// va: 0x002493B0
// tool: the portal's starter code (no AI)
// pure3d::frontend::Page::vfunc_11 (0x002493B0, 77 bytes)
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
    virtual bool vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
};

namespace pure3d { namespace frontend {

class Page
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
    char m_pad04[0x10];
    int m_Field14; // +0x14
    int m_Field18; // +0x18
};

void Page::vfunc_11()
{
    int r_ebp, r_edi, r_esi;

    r_edi = m_Field18;
    r_edi -= m_Field14;
    r_edi >>= 2;
    r_ebp = 0;
    if (r_edi <= 0) goto L_49;
L_15:
    r_esi = *(int*)(m_Field14 + (r_ebp * 4));
    if (((Object*)r_esi)->vfunc_09()) {
        if (!*(bool*)(r_esi + 19)) goto L_43;
        ((Object*)r_esi)->vfunc_11();
        goto L_43;
    }
    if (*(unsigned char*)(r_esi + 44) & 64) {
        ((Object*)r_esi)->vfunc_11();
    }
L_43:
    r_ebp += 1;
    if (r_ebp < r_edi) goto L_15;
L_49:
    ;
}

} }
