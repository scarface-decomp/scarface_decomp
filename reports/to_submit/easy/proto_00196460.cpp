// bin: proto
// va: 0x00196460
// tool: the portal's starter code (no AI)
// PauseMenuPageSerialize::vfunc_39 (0x00196460, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000B9380();
};

extern "C" int __cdecl sub_000B9340(void);
extern "C" bool __stdcall sub_00193FB0(int);

class PauseMenuPageSerialize
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
    virtual void vfunc_38();
    virtual bool vfunc_39(int a1);
    char m_pad04[0x58];
    float m_Field5C; // +0x5C
    bool m_Field60; // +0x60
};

bool PauseMenuPageSerialize::vfunc_39(int a1)
{
    if (sub_00193FB0(a1)) {
        return true;
    }
    ((Object*)sub_000B9340())->sub_000B9380();
    m_Field60 = false;
    m_Field5C = 0.0f;
    return false;
}
