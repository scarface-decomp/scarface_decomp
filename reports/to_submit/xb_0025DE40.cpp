// bin: xb
// va: 0x0025DE40
// what: Returns bit 2 of the flags byte at +0x16 of the object pointed to at +0xA0, or false when the pointer is null.
// tool: Gemini 4 Neon

namespace pure3d {

struct Shader_0025DE40
{
    char m_pad00[0x16];
    unsigned char m_Bits01 : 2;
    unsigned char m_Bit2 : 1; // +0x16 bit 2
};

class SpriteParticleEmitter
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
    char m_pad04[0x9C];
    Shader_0025DE40* m_FieldA0; // +0xA0
};

bool SpriteParticleEmitter::vfunc_12()
{
    if (m_FieldA0)
        return m_FieldA0->m_Bit2;
    return false;
}

}
