// bin: xb
// va: 0x00263FD0
// what: Returns a fixed number kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x000518E0, names and addresses swapped)
// pure3d::d3dExtTODFactor::vfunc_14 (0x00263FD0, 7 bytes)
extern "C" float DAT_004BD4C8;

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
    virtual void vfunc_13();
    virtual float vfunc_14();
};

float d3dExtTODFactor::vfunc_14()
{
    return DAT_004BD4C8;
}

}
