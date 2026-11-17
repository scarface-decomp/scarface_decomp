// bin: xb
// va: 0x0001FC80
// tool: the portal's starter code (no AI)
// sub_0001FC80 (0x0001FC80, 65 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00027600(int);

class Class_0001FC80
{
public:
    int sub_0001FC80(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x12];
    unsigned char m_Field16; // +0x16
};

int Class_0001FC80::sub_0001FC80(int a1)
{
    int t2;

    if (m_Field16 == 3) {
        sub_00027600(m_Field00);
    }
    if (m_Field16 == 4) {
        t2 = sub_00027600(m_Field00);
        m_Field00 = a1;
        m_Field16 = 1;
        return t2;
    }
    m_Field00 = a1;
    m_Field16 = 1;
    return a1;
}
