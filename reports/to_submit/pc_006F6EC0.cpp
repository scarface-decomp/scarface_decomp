// bin: pc
// va: 0x006F6EC0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventChannelSendVolumes::vfunc_03 (0x006F6EC0, 6 bytes)
extern "C" int DAT_0085D4F4;

namespace audio {

class SeqEventChannelSendVolumes
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventChannelSendVolumes::vfunc_03()
{
    return DAT_0085D4F4;
}

}
