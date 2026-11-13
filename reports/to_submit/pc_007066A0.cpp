// bin: pc
// va: 0x007066A0
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x00704A40, names and addresses swapped)
// pure3d::d3dSpecularShader::vfunc_04 (0x007066A0, 6 bytes)
extern "C" char DAT_007FBFE8[];

namespace pure3d {

class d3dSpecularShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dSpecularShader::vfunc_04()
{
    return DAT_007FBFE8;
}

}
