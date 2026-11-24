// bin: xb
// va: 0x002929F0
// what: Returns bit 2 of the flags byte at +0x16 of the object pointed to by +0x38, or false if null.
// tool: Gemini 4 Neon

struct Field38_002929F0
{
    char m_pad00[0x16];
    unsigned char m_Flag0 : 1;
    unsigned char m_Flag1 : 1;
    unsigned char m_Flag2 : 1;
};

namespace pure3d {

class PrimGroup
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
    virtual bool vfunc_12();
    char m_pad04[0x34];
    Field38_002929F0* m_Field38; // +0x38
};

bool PrimGroup::vfunc_12()
{
    if (m_Field38) {
        return m_Field38->m_Flag2;
    }
    return false;
}

}
