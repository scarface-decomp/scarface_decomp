// bin: proto
// va: 0x00285E10
// what: Returns the address of a fixed block in the game's data.
// tool: Claude Fable 5.2 (look-alike of proto 0x000431E0, names and addresses swapped)
// pure3d::d3dPointSpriteShader::vfunc_04 (0x00285E10, 6 bytes)
extern "C" char DAT_00432C04[];

namespace pure3d {

class d3dPointSpriteShader
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void* vfunc_04();
};

void* d3dPointSpriteShader::vfunc_04()
{
    return DAT_00432C04;
}

}
