// bin: proto
// va: 0x00263740
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of proto 0x000431E0, names and addresses swapped)
// pure3d::d3dSimpleShader::vfunc_04 (0x00263740, 6 bytes)
extern "C" char DAT_003AEACC[];

namespace pure3d {

class d3dSimpleShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dSimpleShader::vfunc_04()
{
    return DAT_003AEACC;
}

}
