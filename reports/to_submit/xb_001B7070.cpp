// bin: xb
// va: 0x001B7070
// what: Calls virtual method slot 0 on the embedded member object at +0x5C.
// tool: Gemini 4 Neon

struct Field5C
{
    virtual void vfunc_00();
    void Call00() { vfunc_00(); }
};

namespace GenericWeaponHUD {

class GenericWeaponHUDMenuItem
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    char m_pad04[0x58];
    Field5C m_Field5C; // +0x5C
};

void GenericWeaponHUDMenuItem::vfunc_04()
{
    m_Field5C.Call00();
}

}
