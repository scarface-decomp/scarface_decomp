// bin: proto
// va: 0x00232C10
// what: Returns a fixed number kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of xb 0x000518E0, names and addresses swapped)
// pure3d::d3dExtTODFactor::vfunc_13 (0x00232C10, 7 bytes)
extern "C" float DAT_0048E128;

namespace pure3d {

class d3dExtTODFactor
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
    virtual float vfunc_13();
};

float d3dExtTODFactor::vfunc_13()
{
    return DAT_0048E128;
}

}
