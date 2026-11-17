// bin: xb
// va: 0x0001FD20
// tool: the portal's starter code (no AI)
// sub_0001FD20 (0x0001FD20, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00027600(int);
extern "C" int __cdecl sub_00099C30(int, int, int, int);

class Class_0001FD20
{
public:
    bool sub_0001FD20(int a1, bool a2);
    int m_Field00; // +0x00
    char m_pad04[0xE];
    bool m_Field12; // +0x12
    char m_pad13[0x3];
    unsigned char m_Field16; // +0x16
};

bool Class_0001FD20::sub_0001FD20(int a1, bool a2)
{
    if (m_Field16 == 3) {
        sub_00027600(m_Field00);
    }
    if (m_Field16 == 4) {
        sub_00027600(m_Field00);
    }
    m_Field00 = sub_00099C30(2, a1, 0, 0);
    m_Field12 = a2;
    m_Field16 = 4;
    return a2;
}
