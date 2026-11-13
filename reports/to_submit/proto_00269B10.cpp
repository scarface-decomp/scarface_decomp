// bin: proto
// va: 0x00269B10
// what: Calls one other function and does nothing else.
// tool: Claude Fable 5.2 (look-alike of proto 0x0004C820, names and addresses swapped)
// pure3d::d3dExtStaticShadowGen::vfunc_06 (0x00269B10, 5 bytes)
extern "C" void __cdecl sub_002693F0(void);

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
};

void d3dExtStaticShadowGen::vfunc_06()
{
    sub_002693F0();
}

}
