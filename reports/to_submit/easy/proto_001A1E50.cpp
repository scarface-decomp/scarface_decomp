// bin: proto
// va: 0x001A1E50
// tool: the portal's starter code (no AI)
// CharacterInVehicleSpawnObject::vfunc_35 (0x001A1E50, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field98
{
    void sub_001A6530(int);
};

struct Object
{
    void sub_001A6530(int);
};

class CharacterInVehicleSpawnObject
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
    char m_pad04[0x94];
    Field98* m_Field98; // +0x98
    char m_pad9C[0x4];
    bool m_FieldA0; // +0xA0
    char m_padA1[0x107];
    int m_Field1A8; // +0x1A8
};

void CharacterInVehicleSpawnObject::vfunc_35()
{
    int r_ebx, r_esi;

    if (m_FieldA0) {
        m_Field98->sub_001A6530(64);
    }
    r_esi = 0;
    r_ebx = (int)(&m_Field1A8);
    do {
        if (*(bool*)((int)this + r_esi + 456)) {
            ((Object*)*(int*)r_ebx)->sub_001A6530(64);
        }
        r_esi += 1;
        r_ebx += 4;
    } while (r_esi < 4);
}
