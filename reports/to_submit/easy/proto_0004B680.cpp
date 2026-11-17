// bin: proto
// va: 0x0004B680
// tool: the portal's starter code (no AI)
// sub_0004B680 (0x0004B680, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
};

extern "C" int DAT_0044A528;

class Class_0004B680
{
public:
    void sub_0004B680();
    char m_pad00[0x60];
    int m_Field60; // +0x60
    int m_Field64; // +0x64
};

void Class_0004B680::sub_0004B680()
{
    if (m_Field60) {
        if (m_Field64 <= 0) goto L_19;
        ((Object*)DAT_0044A528)->vfunc_05();
        return;
    }
L_19:
    ;
}
