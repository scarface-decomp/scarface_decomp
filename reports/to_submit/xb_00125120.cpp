// bin: xb
// va: 0x00125120
// what: Returns a fixed number kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x000EFD20, names and addresses swapped)
// AITask_GawkAtCorpse::vfunc_03 (0x00125120, 7 bytes)
extern "C" float DAT_003A01E4;

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
    return DAT_003A01E4;
}
