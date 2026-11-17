// bin: proto
// va: 0x00104970
// tool: the portal's starter code (no AI)
// AIActionRepeatIndefinite::vfunc_03 (0x00104970, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_00102F90();
    int sub_00102FB0();
};

class AIActionRepeatIndefinite
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
    char m_pad04[0x4];
    Field08* m_Field08; // +0x08
    bool m_Field0C; // +0x0C
};

int AIActionRepeatIndefinite::vfunc_03()
{
    if (!m_Field0C) {
        if (m_Field08->sub_00102FB0() != 2) goto L_1F;
        m_Field08->sub_00102F90();
    }
L_1F:
    return 1;
}
