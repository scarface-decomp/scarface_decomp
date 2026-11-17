// bin: pc
// va: 0x006EB0E0
// tool: the portal's starter code (no AI)
// sub_006EB0E0 (0x006EB0E0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field284
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

class Class_006EB0E0
{
public:
    void sub_006EB0E0();
    char m_pad00[0x284];
    Field284* m_Field284; // +0x284
};

void Class_006EB0E0::sub_006EB0E0()
{
    m_Field284->vfunc_01();
}
