// pure3d::d3dTexture (xb): one declaration merged from its matched functions.
// Proven for 10 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class d3dTexture
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual d3dTexture* vfunc_03(unsigned int flags);
    virtual int vfunc_04();
    virtual int vfunc_05();
    virtual int vfunc_06();
    virtual int vfunc_07();
    virtual int vfunc_08();
    virtual int vfunc_09();
    virtual int vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual int vfunc_18(int a1);
    virtual int vfunc_19();
    void sub_002997B0();
    char m_pad04[0xCC];
    int m_FieldD0; // +0xD0
    int m_FieldD4; // +0xD4
    int m_FieldD8; // +0xD8
    int m_FieldDC; // +0xDC
    int m_FieldE0; // +0xE0
    int m_FieldE4; // +0xE4
    char m_padE8[0x8];
    int m_FieldF0; // +0xF0
};
}
