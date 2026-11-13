// bin: xb
// va: 0x002680E0
// what: Calls one other function and does nothing else.
// tool: Claude Fable 5.2 (look-alike of 0x00054F90, names and addresses swapped)
// pure3d::d3dExtVisibilityTest::vfunc_02 (0x002680E0, 5 bytes)
extern "C" void __cdecl sub_0032AC10(void);

namespace pure3d {

class d3dExtVisibilityTest
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
};

void d3dExtVisibilityTest::vfunc_02()
{
    sub_0032AC10();
}

}
