// bin: proto
// va: 0x001A7C30
// tool: the portal's starter code (no AI)
// GangSpawnObject::vfunc_35 (0x001A7C30, 79 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field90
{
    void sub_001A6530(int);
};

struct Object
{
    void sub_001A6530(int);
};

class GangSpawnObject
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
    char m_pad04[0x78];
    int m_Field7C; // +0x7C
    char m_pad80[0x10];
    Field90* m_Field90; // +0x90
    bool m_Field94; // +0x94
};

void GangSpawnObject::vfunc_35()
{
    int r_ebp, r_edi, r_esi;

    r_esi = (int)(((char*)this + 0x85));
    r_edi = (int)(&m_Field7C);
    r_ebp = 2;
    do {
        if (*(unsigned char*)r_esi) {
            ((Object*)*(int*)r_edi)->sub_001A6530(16);
            *(bool*)r_esi = false;
        }
        r_edi += 4;
        r_esi += 1;
        r_ebp -= 1;
    } while (r_ebp);
    if (m_Field94) {
        m_Field90->sub_001A6530(16);
        m_Field94 = false;
    }
}
