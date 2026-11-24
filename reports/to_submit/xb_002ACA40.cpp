// bin: xb
// va: 0x002ACA40
// what: Calls virtual method slot 0 on the subobject at +0x04 of the pointer at +0x0C.
// tool: Gemini 4 Neon

struct SubObject04
{
    virtual void vfunc_00();
    void Call00() { vfunc_00(); }
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
    char m_pad04[0x8];
    Field0C* m_Field0C; // +0x0C
};

void CementLibrary::vfunc_00()
{
    m_Field0C->m_Field04.Call00();
}

}
