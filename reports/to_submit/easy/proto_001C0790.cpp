// bin: proto
// va: 0x001C0790
// tool: the portal's starter code (no AI)
// ExplosionTemplate::vfunc_12 (0x001C0790, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001C06A0(void);

class ExplosionTemplate
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
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
};

void ExplosionTemplate::vfunc_12()
{
    if (m_Field22) {
        sub_001C06A0();
        m_Field22 = false;
    }
}
