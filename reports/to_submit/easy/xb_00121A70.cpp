// bin: xb
// va: 0x00121A70
// tool: the portal's starter code (no AI)
// AIConditionHasScriptAttributeSetToTrue::vfunc_04 (0x00121A70, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    int sub_0002B540(int, int);
};

extern "C" int __cdecl sub_00099BC0(int);

class AIConditionHasScriptAttributeSetToTrue
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

int AIConditionHasScriptAttributeSetToTrue::vfunc_04()
{
    return sub_00099BC0(m_Field08->sub_0002B540((int)(&m_Field0C), 0));
}
