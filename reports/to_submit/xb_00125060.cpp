// bin: xb
// va: 0x00125060
// what: Returns a fixed number kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x000EFD20, names and addresses swapped)
// DriversSmartCollection::vfunc_00 (0x00125060, 7 bytes)
extern "C" float DAT_0039DDD4;

class DriversSmartCollection
{
public:
    virtual float vfunc_00();
};

float DriversSmartCollection::vfunc_00()
{
    return DAT_0039DDD4;
}
