// bin: proto
// va: 0x000F2BD0
// tool: the portal's starter code (no AI)
// AITask_ReactToStaggeredStim::vfunc_36 (0x000F2BD0, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0014C030();
    void sub_001B7A10();
    void sub_00200310(int);
};

extern "C" char DAT_0038A2B8[];
extern "C" int DAT_0040AA24;
extern "C" void __cdecl sub_000EFBB0(void);

class AITask_ReactToStaggeredStim
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
    int sub_000EEAA0(int, int, int);
    char m_pad04[0x48];
    bool m_Field4C; // +0x4C
};

void AITask_ReactToStaggeredStim::vfunc_36()
{
    int local_4;

    sub_000EFBB0();
    if (m_Field4C) {
        ((Object*)(int)(&local_4))->sub_00200310((int)DAT_0038A2B8);
        ((Object*)sub_000EEAA0((int)(&local_4), DAT_0040AA24, 0))->sub_0014C030();
        ((Object*)(int)(&local_4))->sub_001B7A10();
        m_Field4C = false;
    }
}
