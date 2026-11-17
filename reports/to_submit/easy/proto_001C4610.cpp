// bin: proto
// va: 0x001C4610
// tool: the portal's starter code (no AI)
// sub_001C4610 (0x001C4610, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003841B4;
extern "C" char DAT_003A53EC[];
extern "C" float DAT_003A968C;
extern "C" float DAT_003AB1D0;

class Class_001C4610
{
public:
    Class_001C4610* sub_001C4610(int a1, int a2);
    void sub_001C43F0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0xD4];
    float m_FieldD8; // +0xD8
    float m_FieldDC; // +0xDC
    float m_FieldE0; // +0xE0
};

Class_001C4610* Class_001C4610::sub_001C4610(int a1, int a2)
{
    float t4;

    sub_001C43F0(a1, a2);
    m_FieldD8 = DAT_003841B4;
    m_FieldDC = DAT_003AB1D0;
    t4 = DAT_003A968C;
    m_Field00 = (int)DAT_003A53EC;
    m_FieldE0 = t4;
    return this;
}
