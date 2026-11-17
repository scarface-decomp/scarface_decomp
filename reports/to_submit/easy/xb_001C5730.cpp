// bin: xb
// va: 0x001C5730
// tool: the portal's starter code (no AI)
// sub_001C5730 (0x001C5730, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00027600(int);

class Class_001C5730
{
public:
    void sub_001C5730();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

void Class_001C5730::sub_001C5730()
{
    int t1;

    t1 = m_Field00;
    m_Field04 = m_Field00;
    if (m_Field00) {
        sub_00027600(t1);
    }
}
