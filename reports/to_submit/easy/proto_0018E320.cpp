// bin: proto
// va: 0x0018E320
// tool: the portal's starter code (no AI)
// sub_0018E320 (0x0018E320, 71 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE50;
extern "C" char DAT_0039D8BC[];

class Class_0018E320
{
public:
    Class_0018E320* sub_0018E320(int a1, int a2);
    void sub_0016E0E0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x3C];
    int m_Field40; // +0x40
    int m_Field44; // +0x44
    float m_Field48; // +0x48
    float m_Field4C; // +0x4C
    float m_Field50; // +0x50
    float m_Field54; // +0x54
};

Class_0018E320* Class_0018E320::sub_0018E320(int a1, int a2)
{
    sub_0016E0E0(a1, a2);
    m_Field40 = 0;
    m_Field44 = 0;
    m_Field00 = (int)DAT_0039D8BC;
    m_Field48 = 0.0f;
    m_Field4C = 0.0f;
    m_Field50 = 0.0f;
    m_Field54 = DAT_0037CE50;
    return this;
}
