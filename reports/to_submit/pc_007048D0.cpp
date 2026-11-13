// bin: pc
// va: 0x007048D0
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x00704A40, names and addresses swapped)
// pure3d::d3dErrorShader::vfunc_04 (0x007048D0, 6 bytes)
extern "C" char DAT_007FB648[];

namespace pure3d {

class d3dErrorShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dErrorShader::vfunc_04()
{
    return DAT_007FB648;
}

}
