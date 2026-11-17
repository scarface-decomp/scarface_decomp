// bin: xb
// va: 0x001DE8E0
// tool: the portal's starter code (no AI)
// DealerSpawnObject::vfunc_37 (0x001DE8E0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001DE370(int);
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
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual int vfunc_37();
    char m_pad04[0x78];
    int m_Field7C; // +0x7C
    char m_pad80[0xC];
    int m_Field8C; // +0x8C
    char m_pad90[0x4];
    int m_Field94; // +0x94
};

int DealerSpawnObject::vfunc_37()
{
    int r_eax, r_ebp, r_ebx, r_edi;

    r_eax = m_Field94;
    if (r_eax > 0) {
        r_edi = (int)(&m_Field8C);
        r_ebx = (int)(&m_Field7C);
        r_ebp = 4;
        do {
            if (*(unsigned char*)r_edi) {
                r_eax = ((Object*)*(int*)r_ebx)->sub_001DE370(8);
                *(bool*)r_edi = false;
                m_Field94 -= 1;
            }
            r_ebx += 4;
            r_edi += 1;
            r_ebp -= 1;
        } while (r_ebp);
    }
    return r_eax;
}
