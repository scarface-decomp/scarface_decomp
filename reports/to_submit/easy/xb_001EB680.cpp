// bin: xb
// va: 0x001EB680
// tool: the portal's starter code (no AI)
// WorldAmbienceSpawnObject::vfunc_37 (0x001EB680, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field94
{
    int sub_001DE370(int);
};

class WorldAmbienceSpawnObject
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
    char m_pad04[0x90];
    Field94* m_Field94; // +0x94
    int m_Field98; // +0x98
    char m_pad9C[0x17];
    unsigned char m_FieldB3; // +0xB3
};

int WorldAmbienceSpawnObject::vfunc_37()
{
    int r_eax;

    r_eax = *(int*)this;
    r_eax = ((int (__cdecl*)(void))*(int*)(r_eax + 180))();
    if (m_Field98) {
        r_eax |= 1;
    }
    if (m_FieldB3 & 1) {
        r_eax = m_Field94->sub_001DE370(r_eax);
        m_FieldB3 &= 254;
    }
    return r_eax;
}
