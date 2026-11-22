// bin: pc
// va: 0x007010E0
// what: 
// tool: the portal's starter code (no AI)

// movie::PlayerBink::vfunc_14 (PC 0x007010E0, 36 bytes)
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
    virtual bool vfunc_14(int a1);
    char m_pad04[0x18];
    int m_Field1C; // +0x1C
};

bool PlayerBink::vfunc_14(int a1)
{
    if (m_Field1C) {
        *(int*)(a1 + 4) = *(int*)m_Field1C;
        *(int*)a1 = *(int*)(m_Field1C + 4);
        return true;
    }
    return false;
}

}
