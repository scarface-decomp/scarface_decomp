// bin: xb
// va: 0x001FC110
// what: Marks the particle effect template active at +0x22 and calls sub_00087430 on m_Field24 with m_Field20.
// tool: Gemini 4 Neon

struct Field24_001FC110
{
    void sub_00087430(unsigned short value);
};

class ParticleEffectTemplate
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
    char m_pad04[0x1C];
    unsigned short m_Field20; // +0x20
    bool m_Field22; // +0x22
    char m_pad23[0x1];
    Field24_001FC110 m_Field24; // +0x24
};

void ParticleEffectTemplate::vfunc_10()
{
    m_Field22 = true;
    m_Field24.sub_00087430(m_Field20);
}
