// bin: xb
// va: 0x00022990
// tool: the portal's starter code (no AI)
// sub_00022990 (0x00022990, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;
extern "C" char DAT_0039E4DC[];
extern "C" void __cdecl sub_0023E6E0(void);

class Class_00022990
{
public:
    Class_00022990* sub_00022990();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    float m_Field14; // +0x14
    float m_Field18; // +0x18
};

Class_00022990* Class_00022990::sub_00022990()
{
    float t2;

    sub_0023E6E0();
    m_Field14 = 0.0f;
    t2 = DAT_0039D65C;
    m_Field00 = (int)DAT_0039E4DC;
    m_Field18 = t2;
    return this;
}
