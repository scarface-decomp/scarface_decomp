// bin: proto
// va: 0x00237120
// what: Calls one other function and does nothing else.
// tool: Claude Fable 5.2 (look-alike of proto 0x0004C820, names and addresses swapped)
// pure3d::d3dExtVisibilityTest::vfunc_02 (0x00237120, 5 bytes)
extern "C" void __cdecl sub_00315A20(void);

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
    sub_00315A20();
}

}
