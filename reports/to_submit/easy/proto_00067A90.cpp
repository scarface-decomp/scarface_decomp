// bin: proto
// va: 0x00067A90
// tool: the portal's starter code (no AI)
// sub_00067A90 (0x00067A90, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" int DAT_0044FE5C;
extern "C" void __cdecl sub_00067A30(void);

class Class_00067A90
{
public:
    void sub_00067A90();
    char m_pad00[0x18];
    int m_Field18; // +0x18
    char m_pad1C[0x8];
    unsigned short m_Field24; // +0x24
};

void Class_00067A90::sub_00067A90()
{
    m_Field24 -= 1;
    if (!m_Field24) {
        if (m_Field18) goto L_25;
        sub_00067A30();
        ((Object*)DAT_0044FE5C)->vfunc_05((int)this);
    }
L_25:
    ;
}
