// bin: pc
// va: 0x006F94B0
// what: Returns a value kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of pc 0x006DF7F0, names and addresses swapped)
// audio::SeqEventVarTempo::vfunc_03 (0x006F94B0, 6 bytes)
extern "C" int DAT_0085D534;

namespace audio {

class SeqEventVarTempo
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int SeqEventVarTempo::vfunc_03()
{
    return DAT_0085D534;
}

}
