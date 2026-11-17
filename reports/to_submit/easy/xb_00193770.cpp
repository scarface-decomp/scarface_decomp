// bin: xb
// va: 0x00193770
// tool: the portal's starter code (no AI)
// sub_00193770 (0x00193770, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int);
};

class Class_00193770
{
public:
    void sub_00193770();
    char m_pad00[0x20];
    int m_Field20; // +0x20
    int m_Field24; // +0x24
};

void Class_00193770::sub_00193770()
{
    if (*(int*)((int)this + ((m_Field24 + (m_Field24 * 2) + m_Field20) * 4) + 44)) {
        ((Object*)*(int*)((int)this + ((m_Field24 + (m_Field24 * 2) + m_Field20) * 4) + 44))->vfunc_02(0);
    }
}
