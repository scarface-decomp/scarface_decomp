// bin: proto
// va: 0x0001EAB0
// tool: the portal's starter code (no AI)
// sub_0001EAB0 (0x0001EAB0, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00015590(int);
extern "C" void __cdecl sub_00041390(int);

class Class_0001EAB0
{
public:
    void sub_0001EAB0();
    bool m_Field00; // +0x00
    unsigned char m_Field01; // +0x01
    char m_pad02[0x42];
    int m_Field44; // +0x44
    int m_Field48; // +0x48
    int m_Field4C; // +0x4C
    char m_pad50[0xC];
    int m_Field5C; // +0x5C
    char m_pad60[0x4];
    int m_Field64; // +0x64
    char m_pad68[0x10];
    int m_Field78; // +0x78
};

void Class_0001EAB0::sub_0001EAB0()
{
    int t2;

    if (m_Field00) {
        if (m_Field01) {
            m_Field01 = 0;
            m_Field64 = 0;
        }
        m_Field78 = -1;
        if (m_Field44) {
            sub_00041390((int)(&m_Field44));
            m_Field44 = 0;
        }
        t2 = m_Field48;
        if (m_Field48) {
            sub_00015590(t2);
            m_Field48 = 0;
        }
        m_Field4C = 0;
        m_Field5C = 0;
        m_Field00 = false;
    }
}
