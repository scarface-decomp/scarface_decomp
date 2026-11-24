// bin: xb
// va: 0x002ACA50
// what: Calls virtual method slot 1 on the subobject at +0x04 of the pointer at +0x0C.
// tool: Gemini 4 Neon

struct SubObject04
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    void Call01() { vfunc_01(); }
};

struct Field0C
{
    int m_Field00;
    SubObject04 m_Field04; // +0x04
};

namespace core {

class CementLibrary
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void CementLibrary::vfunc_01()
{
    m_Field0C->m_Field04.Call01();
}

}
