// core::XboxDrive (proto): one declaration merged from its matched functions.
// Proven for 11 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace core {
class XboxDrive
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual XboxDrive* vfunc_03(int a1);
    virtual void vfunc_04();
    virtual void* vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual int vfunc_08();
    virtual int vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual int vfunc_12(int a1, int a2);
    virtual void vfunc_13();
    virtual int vfunc_14(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
    virtual void vfunc_15();
    virtual int vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual int vfunc_22(int a1);
    virtual void vfunc_23();
    int sub_002829B0(int);
    char m_pad04[0xCC];
    int m_FieldD0; // +0xD0
    char m_padD4[0x10C];
    int m_Field1E0; // +0x1E0
    int m_Field1E4; // +0x1E4
    int m_Field1E8; // +0x1E8
    char m_pad1EC[0x4];
    int m_Field1F0; // +0x1F0
};
}
