// bin: proto
// va: 0x00027790
// what: Calls a function with this object and one of its fields.
// tool: Claude Fable 5.2 (look-alike of xb 0x00029F40, names and addresses swapped)
// FEGroupObject::vfunc_24 (0x00027790, 14 bytes)
extern "C" void __cdecl sub_00029D60(int, int);

class FEGroupObject
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
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

void FEGroupObject::vfunc_24()
{
    sub_00029D60((int)this, (int)(&m_Field20));
}
