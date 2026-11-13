// bin: proto
// va: 0x00287B20
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of proto 0x000431E0, names and addresses swapped)
// pure3d::d3dCharacterShader::vfunc_04 (0x00287B20, 6 bytes)
extern "C" char DAT_003921A0[];

namespace pure3d {

class d3dCharacterShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dCharacterShader::vfunc_04()
{
    return DAT_003921A0;
}

}
