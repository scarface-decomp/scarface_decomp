// bin: xb
// va: 0x00020BD0
// tool: the portal's starter code (no AI)
// sub_00020BD0 (0x00020BD0, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00480FB8;
extern "C" void __cdecl sub_00012130(int);
extern "C" void __cdecl sub_00048680(int);

class Class_00020BD0
{
public:
    void sub_00020BD0();
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

void Class_00020BD0::sub_00020BD0()
{
    int t2;

    if (m_Field00) {
        if (m_Field01) {
            m_Field01 = 0;
            m_Field64 = 0;
        }
        m_Field78 = DAT_00480FB8;
        if (m_Field44) {
            sub_00048680((int)(&m_Field44));
            m_Field44 = 0;
        }
        t2 = m_Field48;
        if (m_Field48) {
            sub_00012130(t2);
            m_Field48 = 0;
        }
        m_Field4C = 0;
        m_Field5C = 0;
        m_Field00 = false;
    }
}
