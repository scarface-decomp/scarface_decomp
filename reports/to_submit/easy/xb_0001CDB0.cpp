// bin: xb
// va: 0x0001CDB0
// tool: the portal's starter code (no AI)
// WheelExplosionCollisionBroker::vfunc_00 (0x0001CDB0, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000BF7C0(int);
    int sub_000CE360();
    int sub_000CE970();
};

class WheelExplosionCollisionBroker
{
public:
    virtual bool vfunc_00(int a1);
};

bool WheelExplosionCollisionBroker::vfunc_00(int a1)
{
    int t1, t2, t3, t4;

    t1 = ((Object*)a1)->sub_000CE360();
    t2 = *(int*)(t1 + 20);
    if (*(int*)(t1 + 20)) {
        t3 = ((Object*)a1)->sub_000CE970();
        t4 = *(int*)(t3 + 20);
        if (!*(int*)(t3 + 20)) goto L_2A;
        ((Object*)t2)->sub_000BF7C0(t4);
    }
L_2A:
    return false;
}
