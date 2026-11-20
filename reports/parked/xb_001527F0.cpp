// parked: 24/24 bytes (python portal/verify.py work/xb_001527F0.cpp --va 0x001527F0 --bin xb --match vfunc_44@BlendCamera prints VERIFIED); tried a named local with member assignments (stack copy, wrong); stuck at agent.py check: the inline constructor of the returned vector is emitted as a COMDAT next to the target and check cannot pick the target without a match_substr.
// bin: xb
// va: 0x001527F0
// what: Returns a three-number vector of zeros (this camera adds no offset).
// tool: Claude Opus 5.5 (symcov hint: IPickup::Mesh_Offset)
// BlendCamera::vfunc_44 (0x001527F0, 24 bytes)

struct Struct_001527F0
{
    Struct_001527F0(float field00, float field04, float field08)
        : m_Field00(field00), m_Field04(field04), m_Field08(field08)
    {
    }

    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

class Field84;
class BlendCamera
{
public:
    virtual void* vfunc_00();
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
    virtual void vfunc_29(int a1);
    virtual void vfunc_30(int a1);
    virtual void vfunc_31(int a1);
    virtual void vfunc_32(int a1);
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual Struct_001527F0 vfunc_44();
    char m_pad04[0x60];
    int m_Field64; // +0x64
    int m_Field68; // +0x68
    int m_Field6C; // +0x6C
    char m_pad70[0x14];
    Field84* m_Field84; // +0x84
};

// Always the zero vector.
Struct_001527F0 BlendCamera::vfunc_44()
{
    return Struct_001527F0(0.0f, 0.0f, 0.0f);
}
