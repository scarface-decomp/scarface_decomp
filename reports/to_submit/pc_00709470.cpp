// bin: pc
// va: 0x00709470
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x00704A40, names and addresses swapped)
// pure3d::d3dVertexFadeShader::vfunc_04 (0x00709470, 6 bytes)
extern "C" char DAT_007FC9FC[];

namespace pure3d {

class d3dVertexFadeShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dVertexFadeShader::vfunc_04()
{
    return DAT_007FC9FC;
}

}
