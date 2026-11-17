// bin: proto
// va: 0x001FD510
// tool: the portal's starter code (no AI)
// sub_001FD510 (0x001FD510, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06(int);
};

class Class_001FD510
{
public:
    void sub_001FD510(int a1);
    void sub_001FD470();
    char m_pad00[0x8];
    Field08* m_Field08; // +0x08
    char m_pad0C[0x1];
    bool m_Field0D; // +0x0D
    char m_pad0E[0xA];
    int m_Field18; // +0x18
};

void Class_001FD510::sub_001FD510(int a1)
{
    m_Field08->vfunc_06(m_Field18 + a1);
    m_Field18 = m_Field18 + a1;
    if (m_Field0D) {
        sub_001FD470();
    }
}
