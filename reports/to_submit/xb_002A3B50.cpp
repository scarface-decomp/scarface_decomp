// bin: xb
// va: 0x002A3B50
// what: Calls one other function and does nothing else.
// tool: Claude Fable 5.2 (look-alike of 0x00054F90, names and addresses swapped)
// pure3d::d3dExtStaticShadowGen::vfunc_08 (0x002A3B50, 5 bytes)
extern "C" void __cdecl sub_002A34A0(void);

namespace pure3d {

class d3dExtStaticShadowGen
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
};

void d3dExtStaticShadowGen::vfunc_08()
{
    sub_002A34A0();
}

}
