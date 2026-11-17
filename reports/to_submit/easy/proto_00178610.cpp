// bin: proto
// va: 0x00178610
// tool: the portal's starter code (no AI)
// HUDTrackable::vfunc_00 (0x00178610, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int);
};

class HUDTrackable
{
public:
    virtual void vfunc_00(int a1, int a2);
    int m_Field04; // +0x04
    char m_pad08[0x10];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

void HUDTrackable::vfunc_00(int a1, int a2)
{
    int t1, t2;

    if (a1 == m_Field1C) {
        t1 = *(int*)(a2 + 8);
        t2 = m_Field18;
        m_Field04 = *(int*)(a2 + 8);
        ((Object*)t2)->vfunc_03(t1);
        *(unsigned char*)((char*)this - 0x4) |= 1;
    }
}
