// bin: xb
// va: 0x002A0FC0
// what: Switches a global flag off.
// tool: Claude Fable 5.2 (look-alike of 0x002A0F60, names and addresses swapped)
// pure3d::d3dExtXboxControl::vfunc_23 (0x002A0FC0, 8 bytes)
extern "C" bool DAT_0045C348;

namespace pure3d {

class d3dExtXboxControl
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
    virtual void vfunc_23();
};

void d3dExtXboxControl::vfunc_23()
{
    DAT_0045C348 = false;
}

}
