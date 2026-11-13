// bin: pc
// va: 0x006FB240
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventCrossFade::vfunc_03 (0x006FB240, 6 bytes)
extern "C" int DAT_0085D558;

namespace audio {

class SeqEventCrossFade
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventCrossFade::vfunc_03()
{
    return DAT_0085D558;
}

}
