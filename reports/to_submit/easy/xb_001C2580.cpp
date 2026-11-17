// bin: xb
// va: 0x001C2580
// tool: the portal's starter code (no AI)
// sub_001C2580 (0x001C2580, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field6C
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
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14(float);
};

extern "C" float DAT_0039DD50;

class Class_001C2580
{
public:
    void sub_001C2580(int a1);
    char m_pad00[0x6C];
    Field6C* m_Field6C; // +0x6C
    int m_Field70; // +0x70
    short m_Field74; // +0x74
};

void Class_001C2580::sub_001C2580(int a1)
{
    m_Field6C->vfunc_14(((float)a1) / (((float)m_Field74) * DAT_0039DD50));
    m_Field70 = a1;
}
