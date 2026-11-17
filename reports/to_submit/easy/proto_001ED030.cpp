// bin: proto
// va: 0x001ED030
// tool: the portal's starter code (no AI)
// MiniGamePresentationState::vfunc_10 (0x001ED030, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003ABA58[];
extern "C" void __cdecl sub_00065ED0(int, int, int, int, int);

class MiniGamePresentationState
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
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

void MiniGamePresentationState::vfunc_10()
{
    if (!m_Field0C) {
        sub_00065ED0((int)DAT_003ABA58, 0, 0, 0, -1);
    }
    m_Field08 = 8;
    m_Field04 = 4;
}
