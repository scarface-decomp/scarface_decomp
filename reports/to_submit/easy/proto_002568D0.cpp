// bin: proto
// va: 0x002568D0
// tool: the portal's starter code (no AI)
// pure3d::ParticlePointGenerator::vfunc_10 (0x002568D0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CD94;

namespace pure3d {

class ParticlePointGenerator
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
    virtual float vfunc_10(int a1);
    char m_pad04[0x38];
    float m_Field3C; // +0x3C
    float m_Field40; // +0x40
    float m_Field44; // +0x44
};

float ParticlePointGenerator::vfunc_10(int a1)
{
    int r_eax;

    r_eax = a1;
    r_eax -= 1;
    if (r_eax) {
        r_eax -= 1;
        if (r_eax) {
            r_eax -= 1;
            if (r_eax) {
                return DAT_0037CD94;
            }
            return m_Field44;
        }
        return m_Field40;
    }
    return m_Field3C;
}

}
