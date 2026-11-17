// bin: proto
// va: 0x000917B0
// tool: the portal's starter code (no AI)
// WheeledLocomotion::vfunc_07 (0x000917B0, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class WheeledLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int a1);
    char m_pad04[0x15];
    bool m_Field19; // +0x19
    bool m_Field1A; // +0x1A
};

void WheeledLocomotion::vfunc_07(int a1)
{
    m_Field19 = a1 == 1;
    m_Field1A = a1 == 2;
}
