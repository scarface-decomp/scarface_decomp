// bin: xb
// va: 0x00089610
// tool: the portal's starter code (no AI)
// ColliderTracker<ScriptObjectPointer<GameObject*>, 2>::vfunc_00 (0x00089610, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class ColliderTracker_ScriptObjectPointer_GameObject____2_
{
public:
    virtual int vfunc_00(int a1);
};

int ColliderTracker_ScriptObjectPointer_GameObject____2_::vfunc_00(int a1)
{
    return sub_0002AC90(*(int*)((int)this + (a1 * 4) + 16));
}
