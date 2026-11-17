// bin: xb
// va: 0x0001FB50
// tool: the portal's starter code (no AI)
// sub_0001FB50 (0x0001FB50, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00027600(int);

class Class_0001FB50
{
public:
    void sub_0001FB50();
    int m_Field00; // +0x00
    char m_pad04[0x12];
    unsigned char m_Field16; // +0x16
};

void Class_0001FB50::sub_0001FB50()
{
    if (m_Field16 == 3) {
        sub_00027600(m_Field00);
    }
    if (m_Field16 == 4) {
        sub_00027600(m_Field00);
    }
}
