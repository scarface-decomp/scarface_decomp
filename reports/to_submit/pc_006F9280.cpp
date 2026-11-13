// bin: pc
// va: 0x006F9280
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventVarVolume::vfunc_03 (0x006F9280, 6 bytes)
extern "C" int DAT_0085D530;

namespace audio {

class SeqEventVarVolume
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventVarVolume::vfunc_03()
{
    return DAT_0085D530;
}

}
