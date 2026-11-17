// bin: proto
// va: 0x001A57E0
// tool: the portal's starter code (no AI)
// CubeVanSpawnObject::vfunc_35 (0x001A57E0, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field80
{
    void sub_001A6530(int);
};

struct Object
{
    void sub_001A6530(int);
};

class CubeVanSpawnObject
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
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    char m_pad04[0x7C];
    Field80* m_Field80; // +0x80
    int m_Field84; // +0x84
    char m_pad88[0x2C];
    int m_FieldB4; // +0xB4
    char m_padB8[0x8];
    bool m_FieldC0; // +0xC0
};

void CubeVanSpawnObject::vfunc_35()
{
    int r_ebx, r_edi, t2;

    if (m_FieldC0) {
        r_edi = 0;
        if (m_FieldB4 > 0) {
            r_ebx = (int)(&m_Field84);
            do {
                ((Object*)*(int*)r_ebx)->sub_001A6530(64);
                t2 = m_FieldB4;
                r_edi += 1;
                r_ebx += 4;
            } while (r_edi < t2);
        }
        m_Field80->sub_001A6530(64);
        m_FieldC0 = false;
    }
}
