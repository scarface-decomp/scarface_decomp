// bin: xb
// va: 0x00055C20
// what: Calls virtual method slot 0 on the member pointer at +0x84 if it is non-null.
// tool: Gemini 4 Neon

struct Field84
{
    virtual void vfunc_00();
};

namespace renderer {

class PlugInRenderable
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
    char m_pad04[0x80];
    Field84* m_Field84; // +0x84
};

void PlugInRenderable::vfunc_11()
{
    if (m_Field84) {
        m_Field84->vfunc_00();
    }
}

}
