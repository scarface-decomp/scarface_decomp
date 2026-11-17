// bin: proto
// va: 0x000DC600
// tool: the portal's starter code (no AI)
// GlanceAbsentMindedly::vfunc_00 (0x000DC600, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_000BAE80();
};

class GlanceAbsentMindedly
{
public:
    virtual int vfunc_00();
};

int GlanceAbsentMindedly::vfunc_00()
{
    return !((Object*)(int)this + 16)->sub_000BAE80();
}
