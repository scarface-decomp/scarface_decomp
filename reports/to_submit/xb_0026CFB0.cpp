// bin: xb
// va: 0x0026CFB0
// what: Returns bit 2 of the flags byte at +0x16 of the object pointed to by +0x44, or false if null.
// tool: Gemini 4 Neon

struct Field44_0026CFB0
{
    char m_pad00[0x16];
    unsigned char m_Flag0 : 1;
    unsigned char m_Flag1 : 1;
    unsigned char m_Flag2 : 1;
};

namespace pure3d {

class Sprite
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
    char m_pad04[0x40];
    Field44_0026CFB0* m_Field44; // +0x44
};

bool Sprite::vfunc_12()
{
    if (m_Field44) {
        return m_Field44->m_Flag2;
    }
    return false;
}

}
