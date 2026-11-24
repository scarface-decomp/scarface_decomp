// bin: xb
// va: 0x0006D510
// what: Returns the second parameter as a zero-extended 16-bit unsigned integer.
// tool: Gemini 4 Neon

class TTagDerefNode
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual unsigned int vfunc_04(int a1, unsigned short a2, int a3);
};

unsigned int TTagDerefNode::vfunc_04(int, unsigned short a2, int)
{
    return a2;
}
