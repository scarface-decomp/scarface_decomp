// bin: proto
// va: 0x00109970
// what: Returns a fixed number kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of proto 0x000DC5A0, names and addresses swapped)
// AITask_GawkAtCorpse::vfunc_03 (0x00109970, 7 bytes)
extern "C" float DAT_0038AEFC;

class AITask_GawkAtCorpse
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual float vfunc_03();
};

float AITask_GawkAtCorpse::vfunc_03()
{
    return DAT_0038AEFC;
}
