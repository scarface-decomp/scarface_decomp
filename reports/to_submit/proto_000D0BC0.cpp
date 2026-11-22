// bin: proto
// va: 0x000D0BC0
// what: 
// tool: the portal's starter code (no AI)

// AnimationRetargetingAction::vfunc_07 (Proto 0x000D0BC0, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    void sub_000BF5E0(int);
    void sub_000C27D0(int);
};

class AnimationRetargetingAction
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
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
    char m_pad10[0x64];
    bool m_Field74; // +0x74
    char m_pad75[0x3];
    int m_Field78; // +0x78
    char m_pad7C[0x1C];
    bool m_Field98; // +0x98
    char m_pad99[0x3];
    int m_Field9C; // +0x9C
};

void AnimationRetargetingAction::vfunc_07()
{
    if (m_Field74) {
        m_Field0C->sub_000BF5E0((int)(&m_Field78));
    }
    if (m_Field98) {
        m_Field0C->sub_000C27D0((int)(&m_Field9C));
    }
}
