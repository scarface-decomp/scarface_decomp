// bin: xb
// va: 0x00260650
// what: Activates the ambient light by calling vfunc_11 with 1.
// tool: Gemini 4 Neon

namespace pure3d {

class AmbientLight
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(unsigned int slot);
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11(bool enable);
};

#pragma optimize("s", on)
void AmbientLight::vfunc_07(unsigned int)
{
    vfunc_11(true);
}
#pragma optimize("", on)

}
