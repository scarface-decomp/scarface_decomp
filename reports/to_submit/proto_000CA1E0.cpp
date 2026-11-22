// bin: proto
// va: 0x000CA1E0
// what: 
// tool: the portal's starter code (no AI)

// sub_000CA1E0 (Proto 0x000CA1E0, 36 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field0C
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08(int, int);
};

class Class_000CA1E0
{
public:
    void sub_000CA1E0(int a1, int a2);
    char m_pad00[0xC];
    Field0C* m_Field0C; // +0x0C
};

void Class_000CA1E0::sub_000CA1E0(int a1, int a2)
{
    *(int*)a1 = 0;
    *(float*)a2 = 0.0f;
    m_Field0C->vfunc_08(a1, a2);
}
