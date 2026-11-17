// bin: xb
// va: 0x00021070
// tool: the portal's starter code (no AI)
// sub_00021070 (0x00021070, 91 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00012130(int);
extern "C" void __cdecl sub_00012140(int, int);

class Class_00021070
{
public:
    void sub_00021070();
    void sub_00020BD0();
    int sub_00020D90();
    unsigned char m_Field00; // +0x00
    unsigned char m_Field01; // +0x01
    unsigned char m_Field02; // +0x02
    bool m_Field03; // +0x03
    char m_pad04[0x44];
    int m_Field48; // +0x48
    char m_pad4C[0x18];
    int m_Field64; // +0x64
};

void Class_00021070::sub_00021070()
{
    int r_eax;

    r_eax = m_Field03;
    if ((unsigned char)r_eax) {
        r_eax = m_Field48;
        if (r_eax) {
            sub_00012140(r_eax, 0);
        }
        r_eax = m_Field48;
        if (r_eax) {
            r_eax = sub_00012130(r_eax);
            m_Field48 = 0;
        }
        m_Field03 = false;
    }
    if (m_Field02) {
        r_eax = sub_00020D90();
    }
    if (m_Field01) {
        m_Field01 = 0;
        m_Field64 = 0;
    }
    if (m_Field00) {
        sub_00020BD0();
        return;
    }
}
