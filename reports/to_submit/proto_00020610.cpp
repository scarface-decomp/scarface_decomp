// bin: proto
// va: 0x00020610
// what: 
// tool: the portal's starter code (no AI)

// sub_00020610 (Proto 0x00020610, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE60;
extern "C" char DAT_0037DB0C[];
extern "C" void __cdecl sub_001FBFB0(void);

class Class_00020610
{
public:
    Class_00020610* sub_00020610();
    int m_Field00; // +0x00
    char m_pad04[0x10];
    float m_Field14; // +0x14
    float m_Field18; // +0x18
};

Class_00020610* Class_00020610::sub_00020610()
{
    float t2;

    sub_001FBFB0();
    m_Field14 = 0.0f;
    t2 = DAT_0037CE60;
    m_Field00 = (int)DAT_0037DB0C;
    m_Field18 = t2;
    return this;
}
