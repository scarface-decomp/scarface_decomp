// bin: proto
// va: 0x00044D80
// what: 
// tool: the portal's starter code (no AI)

// sub_00044D80 (Proto 0x00044D80, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
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
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21(int);
};

extern "C" int DAT_00464C94;

class Class_00044D80
{
public:
    void sub_00044D80(int a1);
    char m_pad00[0x50];
    unsigned char m_Field50; // +0x50
};

void Class_00044D80::sub_00044D80(int a1)
{
    if (m_Field50 != ((unsigned char)a1)) {
        ((Object*)DAT_00464C94)->vfunc_21(a1);
        m_Field50 = (unsigned char)a1;
    }
}
