// bin: proto
// va: 0x00049090
// tool: the portal's starter code (no AI)
// renderer::CharacterRenderable::vfunc_10 (0x00049090, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0004EF40(void);

namespace renderer {

class CharacterRenderable
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
    virtual void vfunc_09();
    virtual void vfunc_10();
    char m_pad04[0x7C];
    int m_Field80; // +0x80
};

void CharacterRenderable::vfunc_10()
{
    if (m_Field80) {
        sub_0004EF40();
        return;
    }
}

}
