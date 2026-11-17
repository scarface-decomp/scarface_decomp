// bin: proto
// va: 0x0018E1A0
// tool: the portal's starter code (no AI)
// DistanceBubble::vfunc_27 (0x0018E1A0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003F45D8[];
extern "C" char DAT_003F55F0[];
extern "C" int __cdecl sub_00021D50(int);
extern "C" void __cdecl sub_0016E150(void);
extern "C" int __cdecl sub_002C92F8(int, int, int, int, int);

class DistanceBubble
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
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    int m_Field44; // +0x44
};

void DistanceBubble::vfunc_27()
{
    int t2;

    sub_0016E150();
    t2 = m_Field44;
    if (m_Field44) {
        m_Field40 = sub_002C92F8(sub_00021D50(t2), 0, (int)DAT_003F45D8, (int)DAT_003F55F0, 0);
    }
}
