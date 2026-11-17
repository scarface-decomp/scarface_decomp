// bin: xb
// va: 0x00277C10
// tool: the portal's starter code (no AI)
// pure3d::CompositeDrawable::ActivePrimitiveList::vfunc_03 (0x00277C10, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" void __cdecl sub_00027600(int);
extern "C" void __cdecl sub_00277540(void);

namespace pure3d { namespace CompositeDrawable {

class ActivePrimitiveList
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual ActivePrimitiveList* vfunc_03(int a1);
};

ActivePrimitiveList* ActivePrimitiveList::vfunc_03(int a1)
{
    sub_00277540();
    if (a1 & 1) {
        sub_00027600((int)this);
    }
    return this;
}

} }
