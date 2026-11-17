// bin: proto
// va: 0x0023D350
// tool: the portal's starter code (no AI)
// pure3d::Pose::vfunc_06 (0x0023D350, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace pure3d {

class Pose
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06(int a1);
    virtual int vfunc_07(int);
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    char m_pad10[0xD];
    unsigned char m_Field1D; // +0x1D
};

int Pose::vfunc_06(int a1)
{
    int r_eax;

    r_eax = a1;
    if (!a1) {
        if (!(m_Field1D & 1)) goto L_14;
    }
    m_Field0C += 1;
L_14:
    if (m_Field1D & 2) {
        r_eax = vfunc_07(r_eax);
        m_Field1D &= 253;
    }
    return r_eax;
}

}
