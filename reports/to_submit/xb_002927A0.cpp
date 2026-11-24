// bin: xb
// va: 0x002927A0
// what: Forwards two parameters to sub_001E0B70 on the object doubly referenced at +0x44.
// tool: Gemini 4 Neon

#pragma optimize("y", off)

struct Object_002927A0
{
    void sub_001E0B70(int a1, int a2);
};

namespace pure3d {

class ShadowMesh
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
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30(int a1, int a2);
    char m_pad04[0x40];
    int m_Field44; // +0x44
};

void ShadowMesh::vfunc_30(int a1, int a2)
{
    ((Object_002927A0*)*(int*)m_Field44)->sub_001E0B70(a1, a2);
}

}
