// bin: xb
// va: 0x00281D50
// tool: the portal's starter code (no AI)
// pure3d::Pose::vfunc_06 (0x00281D50, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

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
        if (!(m_Field1D & 1)) goto L_16;
    }
    m_Field0C += 1;
L_16:
    if (m_Field1D & 2) {
        r_eax = vfunc_07(r_eax);
        m_Field1D &= 253;
    }
    return r_eax;
}

}
