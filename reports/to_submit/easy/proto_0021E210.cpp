// bin: proto
// va: 0x0021E210
// tool: the portal's starter code (no AI)
// pure3d::Sprite::vfunc_08 (0x0021E210, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int, int);
};

namespace pure3d {

class Sprite
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    void sub_0021E090(int);
    char m_pad04[0x34];
    int m_Field38; // +0x38
    char m_pad3C[0x4];
    int m_Field40; // +0x40
    int m_Field44; // +0x44
    char m_pad48[0x51];
    bool m_Field99; // +0x99
};

void Sprite::vfunc_08()
{
    int r_edi, t3;

    r_edi = 0;
    if (m_Field38 > 0) {
        do {
            ((Object*)*(int*)(m_Field44 + 12))->vfunc_05(0x584554, *(int*)(*(int*)(m_Field40 + (r_edi * 4)) + 12));
            m_Field99 = true;
            sub_0021E090(r_edi);
            t3 = m_Field38;
            r_edi += 1;
        } while (r_edi < t3);
    }
}

}
