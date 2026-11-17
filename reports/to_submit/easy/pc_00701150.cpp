// bin: pc
// va: 0x00701150
// tool: the portal's starter code (no AI)
// movie::PlayerBink::vfunc_16 (0x00701150, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

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
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual int vfunc_16();
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

int PlayerBink::vfunc_16()
{
    int t1;

    t1 = m_Field1C;
    if (m_Field1C) {
        return *(int*)(t1 + 12);
    }
    return 0;
}

}
