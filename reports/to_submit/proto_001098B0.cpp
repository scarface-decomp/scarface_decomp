// bin: proto
// va: 0x001098B0
// what: Returns a fixed number kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of proto 0x000DC5A0, names and addresses swapped)
// DriversSmartCollection::vfunc_00 (0x001098B0, 7 bytes)
extern "C" float DAT_0037F5E0;

class DriversSmartCollection
{
public:
    virtual float vfunc_00();
};

float DriversSmartCollection::vfunc_00()
{
    return DAT_0037F5E0;
}
