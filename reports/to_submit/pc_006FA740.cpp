// bin: pc
// va: 0x006FA740
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventSilence::vfunc_03 (0x006FA740, 6 bytes)
extern "C" int DAT_0085D548;

namespace audio {

class SeqEventSilence
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventSilence::vfunc_03()
{
    return DAT_0085D548;
}

}
