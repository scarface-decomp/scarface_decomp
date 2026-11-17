// bin: proto
// va: 0x00105FF0
// tool: the portal's starter code (no AI)
// sub_00105FF0 (0x00105FF0, 38 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0038CACC[];
extern "C" void __cdecl sub_00102F80(void);

class Class_00105FF0
{
public:
    Class_00105FF0* sub_00105FF0(int a1, float a2);
    int m_Field00; // +0x00
    char m_pad04[0x4];
    int m_Field08; // +0x08
    float m_Field0C; // +0x0C
};

Class_00105FF0* Class_00105FF0::sub_00105FF0(int a1, float a2)
{
    sub_00102F80();
    m_Field08 = a1;
    m_Field00 = (int)DAT_0038CACC;
    m_Field0C = a2;
    return this;
}
