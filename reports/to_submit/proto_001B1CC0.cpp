// bin: proto
// va: 0x001B1CC0
// what: Passes a value to the part at +0x78, then tells a global manager about this object unless a flag says not to.
// tool: Claude Opus 5.5 (transplanted from xb:0x001EB940, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field74
{
    void sub_0001F0C0(int);
};

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
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual int vfunc_30(int);
};

extern "C" int DAT_00462F6C;

class ExplosionObject
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
    virtual void vfunc_08(int a1);
    char m_pad04[0x74];
    Field74 m_Field78; // +0x78
    bool m_Field79; // +0x79
};

void ExplosionObject::vfunc_08(int a1)
{
    int r_eax;

    r_eax = a1;
    m_Field78.sub_0001F0C0(a1);
    r_eax = m_Field79;
    if (!((unsigned char)r_eax)) {
        r_eax = ((Object*)*(int*)(DAT_00462F6C + 12))->vfunc_30((int)this);
    }
}