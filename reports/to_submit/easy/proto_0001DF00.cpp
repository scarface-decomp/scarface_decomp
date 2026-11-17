// bin: proto
// va: 0x0001DF00
// tool: the portal's starter code (no AI)
// sub_0001DF00 (0x0001DF00, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00025160(int);

class Class_0001DF00
{
public:
    int sub_0001DF00(int a1);
    char m_pad00[0x1B];
    unsigned char m_Field1B; // +0x1B
    int m_Field1C; // +0x1C
};

int Class_0001DF00::sub_0001DF00(int a1)
{
    int t2;

    if (m_Field1B == 2) {
        sub_00025160(m_Field1C);
    }
    if (m_Field1B == 3) {
        t2 = sub_00025160(m_Field1C);
        m_Field1C = a1;
        m_Field1B = 1;
        return t2;
    }
    m_Field1C = a1;
    m_Field1B = 1;
    return a1;
}
