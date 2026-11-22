// bin: proto
// va: 0x0001C250
// what: 
// tool: the portal's starter code (no AI)

// WheelExplosionCollisionBroker::vfunc_00 (Proto 0x0001C250, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00026D50();
    int sub_00056450();
    void sub_000B1E90(int);
};

class WheelExplosionCollisionBroker
{
public:
    virtual bool vfunc_00(int a1);
};

bool WheelExplosionCollisionBroker::vfunc_00(int a1)
{
    int t1, t2, t3, t4;

    t1 = ((Object*)a1)->sub_00056450();
    t2 = *(int*)(t1 + 20);
    if (*(int*)(t1 + 20)) {
        t3 = ((Object*)a1)->sub_00026D50();
        t4 = *(int*)(t3 + 20);
        if (!*(int*)(t3 + 20)) goto L_2A;
        ((Object*)t2)->sub_000B1E90(t4);
    }
L_2A:
    return false;
}
