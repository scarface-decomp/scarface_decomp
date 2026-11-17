// bin: proto
// va: 0x0001DF50
// tool: the portal's starter code (no AI)
// sub_0001DF50 (0x0001DF50, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00025160(int);
extern "C" int __cdecl sub_0008E670(int, int, int, int);

class Class_0001DF50
{
public:
    void sub_0001DF50(int a1);
    char m_pad00[0x1B];
    unsigned char m_Field1B; // +0x1B
    int m_Field1C; // +0x1C
};

void Class_0001DF50::sub_0001DF50(int a1)
{
    if (m_Field1B == 2) {
        sub_00025160(m_Field1C);
    }
    if (m_Field1B == 3) {
        sub_00025160(m_Field1C);
    }
    m_Field1C = sub_0008E670(2, a1, 0, 0);
    m_Field1B = 2;
}
