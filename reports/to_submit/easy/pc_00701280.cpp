// bin: pc
// va: 0x00701280
// tool: the portal's starter code (no AI)
// movie::PlayerBink::vfunc_05 (0x00701280, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
};

namespace movie {

class PlayerBink
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    char m_pad04[0x10];
    Field14* m_Field14; // +0x14
    char m_pad18[0xC];
    bool m_Field24; // +0x24
};

void PlayerBink::vfunc_05()
{
    m_Field24 = false;
    m_Field14->vfunc_09();
}

}
