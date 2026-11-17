// bin: pc
// va: 0x00701230
// tool: the portal's starter code (no AI)
// movie::PlayerBink::vfunc_04 (0x00701230, 75 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

namespace movie {

class PlayerBink
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1, int a2, int a3);
    char m_pad04[0xC];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
};

void PlayerBink::vfunc_04(int a1, int a2, int a3)
{
    int r_edi;

    r_edi = m_Field10;
    if (r_edi != a1) {
        m_Field10 = a1;
        if (a1) {
            ((Object*)a1)->vfunc_00();
        }
        if (!r_edi) goto L_25;
        ((Object*)r_edi)->vfunc_01();
    }
L_25:
    r_edi = m_Field14;
    if (r_edi != a2) {
        m_Field14 = a2;
        if (a2) {
            ((Object*)a2)->vfunc_00();
        }
        if (!r_edi) goto L_46;
        ((Object*)r_edi)->vfunc_01();
    }
L_46:
    ;
}

}
