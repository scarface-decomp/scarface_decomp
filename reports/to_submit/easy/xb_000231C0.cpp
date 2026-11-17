// bin: xb
// va: 0x000231C0
// tool: the portal's starter code (no AI)
// FEMeshBroadcast::vfunc_08 (0x000231C0, 22 bytes)
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
    virtual void vfunc_07();
    virtual void vfunc_08(float a1);
    char m_pad04[0xC];
    float m_Field10; // +0x10
    unsigned char m_Field14; // +0x14
};

void FEMeshBroadcast::vfunc_08(float a1)
{
    m_Field14 = (unsigned char)(m_Field14 | 1);
    m_Field10 = a1;
}
