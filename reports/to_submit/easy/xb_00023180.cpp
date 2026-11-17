// bin: xb
// va: 0x00023180
// tool: the portal's starter code (no AI)
// FEMeshBroadcast::vfunc_07 (0x00023180, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class FEMeshBroadcast
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(float a1);
    char m_pad04[0x8];
    float m_Field0C; // +0x0C
    char m_pad10[0x4];
    unsigned char m_Field14; // +0x14
};

void FEMeshBroadcast::vfunc_07(float a1)
{
    m_Field14 = (unsigned char)(m_Field14 | 1);
    m_Field0C = a1;
}
