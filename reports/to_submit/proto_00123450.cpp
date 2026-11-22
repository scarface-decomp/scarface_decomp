// bin: proto
// va: 0x00123450
// what: 
// tool: the portal's starter code (no AI)

// sub_00123450 (Proto 0x00123450, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003902A8;

class Class_00123450
{
public:
    void sub_00123450();
    char m_pad00[0x28];
    float m_Field28; // +0x28
    char m_pad2C[0x90];
    int m_FieldBC; // +0xBC
    char m_padC0[0x68];
    float m_Field128; // +0x128
    char m_pad12C[0x10];
    float m_Field13C; // +0x13C
};

void Class_00123450::sub_00123450()
{
    float t1;

    m_Field128 = 0.0f;
    m_Field13C = 0.0f;
    t1 = DAT_003902A8;
    m_FieldBC = 6;
    m_Field28 = t1;
}
