// bin: proto
// va: 0x00236EF0
// what: Calls one other function and does nothing else.
// tool: Claude Fable 5.2 (look-alike of proto 0x0004C820, names and addresses swapped)
// pure3d::d3dExtAntialiasControl::vfunc_03 (0x00236EF0, 5 bytes)
extern "C" void __cdecl sub_00318CE0(void);

namespace pure3d {

class d3dExtAntialiasControl
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
};

void d3dExtAntialiasControl::vfunc_03()
{
    sub_00318CE0();
}

}
