// bin: proto
// va: 0x000DD320
// what: Returns a fixed number kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of proto 0x000DC5A0, names and addresses swapped)
// PedestriansSmartCollection::vfunc_00 (0x000DD320, 7 bytes)
extern "C" float DAT_003A968C;

class PedestriansSmartCollection
{
public:
    virtual float vfunc_00();
};

float PedestriansSmartCollection::vfunc_00()
{
    return DAT_003A968C;
}
