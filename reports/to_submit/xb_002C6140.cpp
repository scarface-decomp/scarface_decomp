// bin: xb
// va: 0x002C6140
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x0004A760, names and addresses swapped)
// pure3d::d3dNightlightShader::vfunc_04 (0x002C6140, 6 bytes)
extern "C" char DAT_003D5848[];

namespace pure3d {

class d3dNightlightShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dNightlightShader::vfunc_04()
{
    return DAT_003D5848;
}

}
