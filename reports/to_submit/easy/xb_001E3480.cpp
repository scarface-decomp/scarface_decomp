// bin: xb
// va: 0x001E3480
// tool: the portal's starter code (no AI)
// NestSpawnObject::vfunc_35 (0x001E3480, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_002240E0();
};

extern "C" int DAT_00491EF8;
extern "C" bool __cdecl sub_0021FD20(void);

class NestSpawnObject
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
    char m_pad04[0x44];
    bool m_Field48; // +0x48
    bool m_Field49; // +0x49
};

int NestSpawnObject::vfunc_35()
{
    if (m_Field48) {
        if (!m_Field49) goto L_2C;
        if (!((Object*)DAT_00491EF8)->sub_002240E0()) goto L_2C;
        if (!sub_0021FD20()) goto L_2C;
        return 1;
    }
L_2C:
    return 0;
}
