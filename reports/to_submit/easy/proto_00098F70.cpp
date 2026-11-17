// bin: proto
// va: 0x00098F70
// tool: the portal's starter code (no AI)
// HelicopterLocomotion::vfunc_06 (0x00098F70, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_00098D40();
};

extern "C" float DAT_0037CE60;
extern "C" void __cdecl sub_001B7A10(void);

class HelicopterLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    char m_pad0C[0x4];
    float m_Field10; // +0x10
};

void HelicopterLocomotion::vfunc_06()
{
    sub_001B7A10();
    if (m_Field08) {
        m_Field08->sub_00098D40();
    }
    m_Field10 = DAT_0037CE60;
}
