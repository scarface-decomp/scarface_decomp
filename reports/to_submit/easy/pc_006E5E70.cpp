// bin: pc
// va: 0x006E5E70
// tool: the portal's starter code (no AI)
// fight::SequenceAction::vfunc_04 (0x006E5E70, 8 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
};

namespace fight {

class SequenceAction
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void SequenceAction::vfunc_04()
{
    m_Field0C->vfunc_07();
}

}
