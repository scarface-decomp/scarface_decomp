// bin: proto
// va: 0x0001EEF0
// tool: the portal's starter code (no AI)
// sub_0001EEF0 (0x0001EEF0, 91 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00012600(int, int);
extern "C" int __cdecl sub_00015590(int);

class Class_0001EEF0
{
public:
    void sub_0001EEF0();
    void sub_0001EAB0();
    int sub_0001EC70();
    unsigned char m_Field00; // +0x00
    unsigned char m_Field01; // +0x01
    unsigned char m_Field02; // +0x02
    bool m_Field03; // +0x03
    char m_pad04[0x44];
    int m_Field48; // +0x48
    char m_pad4C[0x18];
    int m_Field64; // +0x64
};

void Class_0001EEF0::sub_0001EEF0()
{
    int r_eax;

    r_eax = m_Field03;
    if ((unsigned char)r_eax) {
        r_eax = m_Field48;
        if (r_eax) {
            sub_00012600(r_eax, 0);
        }
        r_eax = m_Field48;
        if (r_eax) {
            r_eax = sub_00015590(r_eax);
            m_Field48 = 0;
        }
        m_Field03 = false;
    }
    if (m_Field02) {
        r_eax = sub_0001EC70();
    }
    if (m_Field01) {
        m_Field01 = 0;
        m_Field64 = 0;
    }
    if (m_Field00) {
        sub_0001EAB0();
        return;
    }
}
