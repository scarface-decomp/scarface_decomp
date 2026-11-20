// bin: xb
// va: 0x00269B50
// what: Sets a global value used by the colour-tint extension.
// tool: Claude Opus 5.5 (symcov hint: EARS::Modules::ChatterPlaybackManager::GetChatGroupHash, link-order)
// pure3d::d3dExtUnLitColourTint::vfunc_02 (0x00269B50, 19 bytes)
// pure3d is built with frame pointers (push ebp; mov ebp, esp), like the other pure3d functions.
#pragma optimize("y", off)

extern "C" void __cdecl sub_0029F7C0(int value);

namespace pure3d {

class d3dExtUnLitColourTint
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int value);
};

// Forwards the value to the global setter.
void d3dExtUnLitColourTint::vfunc_02(int value)
{
    sub_0029F7C0(value);
}

}
