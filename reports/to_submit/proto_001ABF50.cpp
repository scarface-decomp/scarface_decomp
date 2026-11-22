// bin: proto
// va: 0x001ABF50
// what: When a flag is set, sends a message (64) to every object in its list and clears the flag.
// tool: Claude Opus 5.5 (transplanted from xb:0x001E5420, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001A6530(int);
};

class ScatteredEnemyCharacterGeneratorSpawnObject
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
    virtual void vfunc_37();
    char m_pad04[0x78];
    int m_Field7C; // +0x7C
    char m_pad80[0x30];
    int m_FieldB0; // +0xB0
    char m_padB4[0x1A];
    bool m_FieldCE; // +0xCE
};

void ScatteredEnemyCharacterGeneratorSpawnObject::vfunc_37()
{
    int r_eax, r_edi, r_esi;

    r_eax = m_FieldCE;
    if ((unsigned char)r_eax) {
        r_eax = m_FieldB0;
        r_esi = 0;
        if (r_eax > 0) {
            r_edi = (int)(&m_Field7C);
            do {
                ((Object*)*(int*)r_edi)->sub_001A6530(64);
                r_eax = m_FieldB0;
                r_esi += 1;
                r_edi += 4;
            } while (r_esi < r_eax);
        }
        m_FieldCE = false;
    }
}