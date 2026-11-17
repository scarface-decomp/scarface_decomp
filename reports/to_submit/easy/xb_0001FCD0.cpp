// bin: xb
// va: 0x0001FCD0
// tool: the portal's starter code (no AI)
// sub_0001FCD0 (0x0001FCD0, 66 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00027600(int);
extern "C" int __cdecl sub_00099C30(int, int, int, int);

class Class_0001FCD0
{
public:
    void sub_0001FCD0(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x12];
    unsigned char m_Field16; // +0x16
};

void Class_0001FCD0::sub_0001FCD0(int a1)
{
    if (m_Field16 == 3) {
        sub_00027600(m_Field00);
    }
    if (m_Field16 == 4) {
        sub_00027600(m_Field00);
    }
    m_Field00 = sub_00099C30(2, a1, 0, 0);
    m_Field16 = 3;
}
