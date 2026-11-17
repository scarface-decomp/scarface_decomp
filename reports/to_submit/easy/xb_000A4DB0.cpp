// bin: xb
// va: 0x000A4DB0
// tool: the portal's starter code (no AI)
// HelicopterLocomotion::vfunc_04 (0x000A4DB0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_000A4CB0();
};

extern "C" float DAT_0039D65C;
extern "C" void __cdecl sub_002A9290(void);

class HelicopterLocomotion
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    char m_pad0C[0x4];
    float m_Field10; // +0x10
};

void HelicopterLocomotion::vfunc_04()
{
    sub_002A9290();
    if (m_Field08) {
        m_Field08->sub_000A4CB0();
    }
    m_Field10 = DAT_0039D65C;
}
