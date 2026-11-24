// bin: xb
// va: 0x00197060
// what: Calls virtual method slot 1 on the embedded member object at +0x0C.
// tool: Gemini 4 Neon

struct Field0C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    void Call01() { vfunc_01(); }
};

namespace ExoticsHUD2 {

class ExoticsHUDMenuItem
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    char m_pad04[0x8];
    Field0C m_Field0C; // +0x0C
};

void ExoticsHUDMenuItem::vfunc_04()
{
    m_Field0C.Call01();
}

}
