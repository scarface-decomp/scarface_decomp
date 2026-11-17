// bin: proto
// va: 0x00207130
// tool: the portal's starter code (no AI)
// pure3d::frontend::Menu::vfunc_08 (0x00207130, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field24
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
};

extern "C" void __cdecl sub_00249400(void);

namespace pure3d { namespace frontend {

class Menu
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
    char m_pad04[0xD];
    bool m_Field11; // +0x11
    char m_pad12[0x12];
    Field24* m_Field24; // +0x24
};

void Menu::vfunc_08()
{
    Field24* t2;

    sub_00249400();
    t2 = m_Field24;
    if (m_Field24) {
        *(bool*)((int)t2 + 17) = m_Field11;
        m_Field24->vfunc_08();
        return;
    }
}

} }
