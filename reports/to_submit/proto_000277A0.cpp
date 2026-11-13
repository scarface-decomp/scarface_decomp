// bin: proto
// va: 0x000277A0
// what: Calls a function on a part of this object, with 8.
// tool: Claude Fable 5.2 (look-alike of xb 0x00029F50, names and addresses swapped)
// FEGroupObject::vfunc_25 (0x000277A0, 15 bytes)
extern "C" void __cdecl sub_00029DC0(int, int);

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
    virtual void vfunc_25();
};

void FEGroupObject::vfunc_25()
{
    sub_00029DC0((int)this + 32, 8);
}
