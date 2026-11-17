// bin: xb
// va: 0x0023D880
// tool: the portal's starter code (no AI)
// sub_0023D880 (0x0023D880, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

class Class_0023D880
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
    int sub_0023D880(int a1);
};

int Class_0023D880::sub_0023D880(int a1)
{
    return vfunc_06() == a1;
}
