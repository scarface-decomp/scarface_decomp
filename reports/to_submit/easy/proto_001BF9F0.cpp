// bin: proto
// va: 0x001BF9F0
// tool: the portal's starter code (no AI)
// CharacterTemplate::vfunc_12 (0x001BF9F0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00015510(int);

class CharacterTemplate
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
    virtual void vfunc_11();
    virtual void vfunc_12();
    char m_pad04[0x70];
    int m_Field74; // +0x74
};

void CharacterTemplate::vfunc_12()
{
    int t1;

    t1 = m_Field74;
    if (m_Field74) {
        sub_00015510(t1);
    }
}
