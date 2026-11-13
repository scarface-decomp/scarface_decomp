// bin: pc
// va: 0x006F6960
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventNestTrack::vfunc_03 (0x006F6960, 6 bytes)
extern "C" int DAT_0085D4F0;

namespace audio {

class SeqEventNestTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventNestTrack::vfunc_03()
{
    return DAT_0085D4F0;
}

}
