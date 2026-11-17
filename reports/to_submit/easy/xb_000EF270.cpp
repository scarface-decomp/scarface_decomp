// bin: xb
// va: 0x000EF270
// tool: the portal's starter code (no AI)
// AIActionTreeCreatingTask::vfunc_00 (0x000EF270, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_000CA1C0();
};

class AIActionTreeCreatingTask
{
public:
    virtual int vfunc_00();
};

int AIActionTreeCreatingTask::vfunc_00()
{
    return !((Object*)(int)this + 264)->sub_000CA1C0();
}
