// bin: proto
// va: 0x001A6930
// tool: the portal's starter code (no AI)
// DealerSpawnObject::vfunc_35 (0x001A6930, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001A6530(int);
};

class DealerSpawnObject
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
    virtual int vfunc_35();
    char m_pad04[0x7C];
    int m_Field80; // +0x80
    char m_pad84[0xC];
    int m_Field90; // +0x90
    char m_pad94[0x4];
    int m_Field98; // +0x98
};

int DealerSpawnObject::vfunc_35()
{
    int r_eax, r_ebp, r_ebx, r_edi;

    r_eax = m_Field98;
    if (r_eax > 0) {
        r_edi = (int)(&m_Field90);
        r_ebx = (int)(&m_Field80);
        r_ebp = 4;
        do {
            if (*(unsigned char*)r_edi) {
                r_eax = ((Object*)*(int*)r_ebx)->sub_001A6530(8);
                *(bool*)r_edi = false;
                m_Field98 -= 1;
            }
            r_ebx += 4;
            r_edi += 1;
            r_ebp -= 1;
        } while (r_ebp);
    }
    return r_eax;
}
