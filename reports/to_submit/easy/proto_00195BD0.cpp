// bin: proto
// va: 0x00195BD0
// tool: the portal's starter code (no AI)
// sub_00195BD0 (0x00195BD0, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field44
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
};

struct Field58
{
    void sub_001701F0();
};

extern "C" char DAT_0039F424[];
extern "C" int __cdecl sub_00065830(int, int);

class Class_00195BD0
{
public:
    void sub_00195BD0();
    void sub_00195AF0(int);
    char m_pad00[0x44];
    Field44* m_Field44; // +0x44
    char m_pad48[0x10];
    Field58* m_Field58; // +0x58
};

void Class_00195BD0::sub_00195BD0()
{
    if (m_Field44) {
        if (!m_Field58) goto L_3B;
        sub_00195AF0(sub_00065830((int)DAT_0039F424, *(int*)(m_Field44->vfunc_07() + 8)));
        m_Field58->sub_001701F0();
        return;
    }
L_3B:
    ;
}
