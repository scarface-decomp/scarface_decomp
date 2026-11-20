// bin: xb
// va: 0x002A08A0
// what: Turns off four global on/off switches of the Xbox render control.
// tool: Claude Opus 5.5 (symcov hint: MemCard_SaveInit())
// pure3d::d3dExtXboxControl::vfunc_07 (0x002A08A0)
// Class shape from reports/classes/xb/pure3d__d3dExtXboxControl.h.
extern "C" bool DAT_004BD4CD;
extern "C" bool DAT_004BD4CE;
extern "C" bool DAT_004BD4CF;
extern "C" bool DAT_004BD4D1;
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
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27(int a1);
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48(int a1);
    virtual void vfunc_49();
};
}

namespace pure3d {

// Clears the four switches.
void d3dExtXboxControl::vfunc_07()
{
    DAT_004BD4CD = false;
    DAT_004BD4CF = false;
    DAT_004BD4CE = false;
    DAT_004BD4D1 = false;
}

}
