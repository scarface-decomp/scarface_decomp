// bin: proto
// va: 0x0009FBC0
// tool: the portal's starter code (no AI)
// sub_0009FBC0 (0x0009FBC0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0009FBC0
{
public:
    void sub_0009FBC0(int a1);
    int m_Field00; // +0x00
};

void Class_0009FBC0::sub_0009FBC0(int a1)
{
    if (m_Field00 != 145) {
        m_Field00 = 145;
        return;
    }
    m_Field00 = a1;
}
