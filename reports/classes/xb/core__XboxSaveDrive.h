// core::XboxSaveDrive (xb): one declaration merged from its matched functions.
// Proven for 7 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace core {
class XboxSaveDrive
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    virtual int vfunc_02(int a1);
    virtual XboxSaveDrive* vfunc_03(int a1);
    virtual void vfunc_04();
    virtual void* vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual int vfunc_12(int a1, int a2);
    virtual void vfunc_13(int, int);
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual int vfunc_22(int a1);
    char m_pad04[0xE0];
    int m_FieldE4; // +0xE4
    int m_FieldE8; // +0xE8
};
}
