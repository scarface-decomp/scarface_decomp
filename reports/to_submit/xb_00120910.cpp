// bin: xb
// va: 0x00120910
// what: Calls vfunc_06 and returns 2 if it returned 1, otherwise returns 1.
// tool: Gemini 4 Neon

class AIActionCustomLogicalEffect
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual int vfunc_06();
};

int AIActionCustomLogicalEffect::vfunc_03()
{
    return (vfunc_06() == 1) ? 2 : 1;
}
