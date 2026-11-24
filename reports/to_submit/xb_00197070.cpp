// bin: xb
// va: 0x00197070
// what: Calls virtual slot 0 on the embedded member object at +0x14.
// tool: Gemini 4 Neon

struct Embedded_00197070
{
    virtual void vfunc_00();
    void Call() { vfunc_00(); }
};

class GenericMenuClient
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    char m_pad04[0x10];
    Embedded_00197070 m_Field14; // +0x14
};

void GenericMenuClient::vfunc_01()
{
    m_Field14.Call();
}
