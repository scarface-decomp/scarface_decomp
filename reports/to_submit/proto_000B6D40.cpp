// bin: proto
// va: 0x000B6D40
// what: 
// tool: the portal's starter code (no AI)

// ScriptContextProperties::vfunc_05 (Proto 0x000B6D40, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_00028C40(int);

class ScriptContextProperties
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    char m_pad04[0x24];
    float m_Field28; // +0x28
    float m_Field2C; // +0x2C
};

void ScriptContextProperties::vfunc_05(int a1)
{
    float t2;

    sub_00028C40(a1);
    t2 = m_Field28;
    m_Field2C = t2 * t2;
}
