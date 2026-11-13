// bin: xb
// va: 0x001276B0
// what: Returns a fixed number kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x000EFD20, names and addresses swapped)
// AIActionTreeCreatingTask::vfunc_03 (0x001276B0, 7 bytes)
extern "C" float DAT_003A4974;

class AIActionTreeCreatingTask
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual float vfunc_03();
};

float AIActionTreeCreatingTask::vfunc_03()
{
    return DAT_003A4974;
}
