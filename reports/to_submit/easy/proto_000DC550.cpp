// bin: proto
// va: 0x000DC550
// tool: the portal's starter code (no AI)
// PedestriansSmartCollection::vfunc_01 (0x000DC550, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0014A290();
};

class PedestriansSmartCollection
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};

int PedestriansSmartCollection::vfunc_01(int a1)
{
    return !((Object*)a1)->sub_0014A290();
}
