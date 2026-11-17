// bin: xb
// va: 0x000EFCD0
// tool: the portal's starter code (no AI)
// DriversSmartCollection::vfunc_01 (0x000EFCD0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00166CE0();
};

class DriversSmartCollection
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01(int a1);
};

int DriversSmartCollection::vfunc_01(int a1)
{
    return ((Object*)a1)->sub_00166CE0() != 0;
}
