// bin: proto
// va: 0x000DC590
// what: Returns a fixed number kept in the game's data.
// tool: Claude Fable 5.2 (look-alike of proto 0x000DC5A0, names and addresses swapped)
// AmbientGazeTask::vfunc_05 (0x000DC590, 7 bytes)
extern "C" float DAT_0037CE50;

class AmbientGazeTask
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual float vfunc_05();
};

float AmbientGazeTask::vfunc_05()
{
    return DAT_0037CE50;
}
