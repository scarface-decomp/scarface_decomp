// bin: xb
// va: 0x00269B30
// what: Sets a global on/off switch used by the colour-tint extension.
// tool: Claude Opus 5.5 (symcov hint: EARS::Modules::ChatterPlaybackManager::GetChatGroupHash, link-order)
// pure3d::d3dExtUnLitColourTint::vfunc_01 (0x00269B30, 19 bytes)
// pure3d is built with frame pointers (push ebp; mov ebp, esp), like the other pure3d functions.
#pragma optimize("y", off)

extern "C" void __cdecl sub_0029F7B0(bool value);

namespace pure3d {

class d3dExtUnLitColourTint
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01(bool value);
};

// Forwards the value to the global setter.
void d3dExtUnLitColourTint::vfunc_01(bool value)
{
    sub_0029F7B0(value);
}

}
