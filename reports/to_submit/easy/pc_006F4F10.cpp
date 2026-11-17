// bin: pc
// va: 0x006F4F10
// tool: the portal's starter code (no AI)
// sub_006F4F10 (0x006F4F10, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field2DC
{
    void sub_006F1340();
};

extern "C" char DAT_00772B5C[];

class Class_006F4F10
{
public:
    Class_006F4F10* sub_006F4F10(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    char m_pad08[0x2D0];
    int m_Field2D8; // +0x2D8
    Field2DC m_Field2DC; // +0x2DC
    char m_pad2DD[0x3];
    int m_Field2E0; // +0x2E0
    int m_Field2E4; // +0x2E4
    int m_Field2E8; // +0x2E8
    int m_Field2EC; // +0x2EC
    int m_Field2F0; // +0x2F0
};

Class_006F4F10* Class_006F4F10::sub_006F4F10(int a1)
{
    m_Field00 = (int)DAT_00772B5C;
    m_Field04 = a1;
    m_Field2D8 = 0;
    m_Field2DC.sub_006F1340();
    m_Field2E0 = 0;
    m_Field2E4 = 0;
    m_Field2E8 = 0;
    m_Field2EC = 0;
    m_Field2F0 = 0;
    return this;
}
