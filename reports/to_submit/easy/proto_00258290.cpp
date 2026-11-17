// bin: proto
// va: 0x00258290
// tool: the portal's starter code (no AI)
// pure3d::SpriteParticleEmitter::vfunc_21 (0x00258290, 69 bytes)
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
};

namespace pure3d {

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
    char m_pad04[0x7C];
    int m_Field80; // +0x80
    char m_pad84[0xCC];
    int m_Field150; // +0x150
    char m_pad154[0xC];
    int m_Field160; // +0x160
    char m_pad164[0x8];
    int m_Field16C; // +0x16C
    char m_pad170[0x8];
    int m_Field178; // +0x178
    char m_pad17C[0x10];
    int m_Field18C; // +0x18C
    char m_pad190[0x8];
    int m_Field198; // +0x198
    char m_pad19C[0x4];
    int m_Field1A0; // +0x1A0
    char m_pad1A4[0x4];
    int m_Field1A8; // +0x1A8
};

void SpriteParticleEmitter::vfunc_21()
{
    int t1;

    m_Field150 = 0x3F800000;
    m_Field160 = 0x3F800000;
    m_Field16C = 0x3F800000;
    m_Field178 = 0x3F800000;
    m_Field18C = 0x3F800000;
    m_Field198 = 0x3F800000;
    m_Field1A0 = 0x3F800000;
    m_Field1A8 = 0x3F800000;
    t1 = m_Field80;
    if (m_Field80) {
        ((Object*)t1)->vfunc_11();
        return;
    }
}

}
