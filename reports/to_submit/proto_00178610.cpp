// bin: proto
// va: 0x00178610
// what: When the value given matches the one at +0x1C, stores a new number and passes it to a linked object.
// tool: Claude Opus 5.5 (transplanted from xb:0x001A30E0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int);
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
    int r_eax, t1;

    r_eax = a1;
    if (a1 == m_Field1C) {
        r_eax = *(int*)(a2 + 8);
        t1 = m_Field18;
        m_Field04 = r_eax;
        r_eax = ((Object*)t1)->vfunc_03(r_eax);
        *(unsigned char*)((char*)this - 0x4) |= 1;
    }
}