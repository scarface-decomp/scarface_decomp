// bin: proto
// va: 0x000531B0
// what: Always returns 0x2000000.
// tool: Claude Fable 5.2 (look-alike of xb 0x0005D7C0, names and addresses swapped)
// renderer::VehicleContainer::vfunc_23 (0x000531B0, 6 bytes)
namespace renderer {

class VehicleContainer
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
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual int vfunc_23();
};

int VehicleContainer::vfunc_23()
{
    return 0x2000000;
}

}
