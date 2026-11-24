// bin: xb
// va: 0x00120040
// what: Calls virtual method slot 1 on m_Field08 and returns 2 if it returned 0.
// tool: Gemini 4 Neon

struct Field08_00120040
{
    virtual void vfunc_00();
    virtual int vfunc_01();
};

class AIActionSkipIfFail
{
public:
    virtual void vfunc_00();
    virtual int vfunc_01();
    char m_pad04[0x4];
    Field08_00120040* m_Field08; // +0x08
};

int AIActionSkipIfFail::vfunc_01()
{
    int result = m_Field08->vfunc_01();
    if (!result) {
        result = 2;
    }
    return result;
}
