// bin: xb
// va: 0x001CD050
// what: Calls virtual method slot 0 on the embedded member object at +0x44.
// tool: Gemini 4 Neon

struct Field44
{
    virtual void vfunc_00();
    void Call00() { vfunc_00(); }
};

namespace PauseMenuPageRewards {

class PauseMenuPageCheatItem
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    char m_pad04[0x40];
    Field44 m_Field44; // +0x44
};

void PauseMenuPageCheatItem::vfunc_04()
{
    m_Field44.Call00();
}

}
