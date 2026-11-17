// pure3d::d3dDisplay (proto): one declaration merged from its matched functions.
// Proven for 11 functions: each compiles to the game's bytes with this class
// in place of its own copy (portal/scripts/merge_classes.py --verify). Members and virtual
// functions no matched function uses yet are padding and `vfunc_NN` stand-ins.

namespace pure3d {
class d3dDisplay
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual d3dDisplay* vfunc_03(int a1);
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
    virtual int vfunc_08();
    virtual int vfunc_09();
    virtual void vfunc_10();
    virtual int vfunc_11();
    virtual int vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual int vfunc_16(int a1, int a2, int a3);
    virtual void* vfunc_17();
    virtual float vfunc_18();
    virtual float vfunc_19();
    virtual float vfunc_20();
    void sub_00264490();
    char m_pad04[0xC];
    int m_Field10; // +0x10
    char m_pad14[0x45C];
    int m_Field470; // +0x470
    int m_Field474; // +0x474
    int m_Field478; // +0x478
    int m_Field47C; // +0x47C
    int m_Field480; // +0x480
    char m_pad484[0x14];
    int m_Field498; // +0x498
    char m_pad49C[0x4];
    int m_Field4A0; // +0x4A0
    float m_Field4A4; // +0x4A4
    float m_Field4A8; // +0x4A8
    float m_Field4AC; // +0x4AC
    float m_Field4B0; // +0x4B0
    float m_Field4B4; // +0x4B4
};
}
