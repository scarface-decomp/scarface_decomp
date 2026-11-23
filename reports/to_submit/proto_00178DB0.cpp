// bin: proto
// va: 0x00178DB0
// what: 
// tool: the portal's starter code (no AI)

// sub_00178DB0 (Proto 0x00178DB0, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field54
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int);
};

extern "C" char DAT_00399E04[];
extern "C" void __cdecl sub_00074250(int);

class Class_00178DB0
{
public:
    void sub_00178DB0();
    char m_pad00[0x3C];
    unsigned char m_Field3C; // +0x3C
    char m_pad3D[0x17];
    Field54* m_Field54; // +0x54
    char m_pad58[0x2C];
    int m_Field84; // +0x84
    char m_pad88[0x31C];
    float m_Field3A4; // +0x3A4
};

void Class_00178DB0::sub_00178DB0()
{
    if (m_Field84) {
        m_Field54->vfunc_02(0);
        m_Field3C = (unsigned char)(m_Field3C | 1);
        m_Field3A4 = 0.0f;
        m_Field84 = 2;
        sub_00074250((int)DAT_00399E04);
    }
}
