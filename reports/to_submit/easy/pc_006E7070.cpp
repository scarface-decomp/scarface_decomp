// bin: pc
// va: 0x006E7070
// tool: the portal's starter code (no AI)
// sub_006E7070 (0x006E7070, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field00
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_006E7070
{
public:
    void sub_006E7070();
    Field00* m_Field00; // +0x00
};

void Class_006E7070::sub_006E7070()
{
    m_Field00->vfunc_01();
    m_Field00 = 0;
}
