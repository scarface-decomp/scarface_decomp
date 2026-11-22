// bin: proto
// va: 0x000DC570
// what: 
// tool: the portal's starter code (no AI)

// DriversSmartCollection::vfunc_01 (Proto 0x000DC570, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0014A290();
};

class DriversSmartCollection
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};

int DriversSmartCollection::vfunc_01(int a1)
{
    return ((Object*)a1)->sub_0014A290() != 0;
}
