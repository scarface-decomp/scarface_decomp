// bin: proto
// va: 0x002B6680
// tool: the portal's starter code (no AI)
// sub_002B6680 (0x002B6680, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00025160(int);

class Class_002B6680
{
public:
    void sub_002B6680();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

void Class_002B6680::sub_002B6680()
{
    int t1;

    t1 = m_Field00;
    m_Field04 = m_Field00;
    if (m_Field00) {
        sub_00025160(t1);
    }
}
