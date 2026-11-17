// bin: proto
// va: 0x001FB320
// tool: the portal's starter code (no AI)
// sub_001FB320 (0x001FB320, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001FB320
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
    int sub_001FB320(int a1);
};

int Class_001FB320::sub_001FB320(int a1)
{
    return vfunc_06() == a1;
}
