// bin: pc
// va: 0x006F8650
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventPlayTrack::vfunc_03 (0x006F8650, 6 bytes)
extern "C" int DAT_0085D520;

namespace audio {

class SeqEventPlayTrack
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventPlayTrack::vfunc_03()
{
    return DAT_0085D520;
}

}
