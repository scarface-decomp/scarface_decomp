// bin: xb
// va: 0x00125930
// what: Returns a fixed number kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of 0x000EFD20, names and addresses swapped)
// AITask_DealerWarnTony::vfunc_03 (0x00125930, 7 bytes)
extern "C" float DAT_003CA880;

class AITask_DealerWarnTony
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual float vfunc_03();
};

float AITask_DealerWarnTony::vfunc_03()
{
    return DAT_003CA880;
}
