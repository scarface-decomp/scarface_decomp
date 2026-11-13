// bin: proto
// va: 0x00050340
// what: Always returns 0x1000000.
// tool: Claude Fable 5.2 (look-alike of xb 0x000517F0, names and addresses swapped)
// renderer::DecalContainer::vfunc_23 (0x00050340, 6 bytes)
namespace renderer {

class DecalContainer
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

int DecalContainer::vfunc_23()
{
    return 0x1000000;
}

}
