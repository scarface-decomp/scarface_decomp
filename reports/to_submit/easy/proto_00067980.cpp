// bin: proto
// va: 0x00067980
// tool: the portal's starter code (no AI)
// sub_00067980 (0x00067980, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
    void sub_00024B30(int);
    void sub_00024B50();
};

extern "C" int DAT_003F9DB4;
extern "C" int DAT_003F9DB8;
extern "C" int DAT_0044FE6C;
extern "C" void __cdecl sub_00025160(int);

class Class_00067980
{
public:
    void sub_00067980();
    char m_pad00[0x4];
    int m_Field04; // +0x04
    char m_pad08[0x4];
    unsigned char m_Field0C; // +0x0C
};

void Class_00067980::sub_00067980()
{
    int local_4;

    if (m_Field0C == 255) {
        if (m_Field04 == DAT_003F9DB8) goto L_42;
        ((Object*)(int)(&local_4))->sub_00024B30(DAT_003F9DB4);
        sub_00025160(m_Field04);
        m_Field04 = DAT_003F9DB8;
        ((Object*)(int)(&local_4))->sub_00024B50();
    }
L_42:
    ((Object*)DAT_0044FE6C)->vfunc_05((int)this);
}
