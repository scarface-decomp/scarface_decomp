// bin: proto
// va: 0x002588E0
// tool: the portal's starter code (no AI)
// pure3d::ParticleEmitter::vfunc_30 (0x002588E0, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

namespace pure3d {

class ParticleEmitter
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
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30(int a1);
    char m_pad04[0x78];
    int m_Field7C; // +0x7C
};

void ParticleEmitter::vfunc_30(int a1)
{
    int t2;

    if (a1 != m_Field7C) {
        if (a1) {
            ((Object*)a1)->vfunc_00();
        }
        t2 = m_Field7C;
        if (m_Field7C) {
            ((Object*)t2)->vfunc_01();
        }
        m_Field7C = a1;
    }
}

}
