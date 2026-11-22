// bin: proto
// va: 0x000D9C80
// what: 
// tool: the portal's starter code (no AI)

// sub_000D9C80 (Proto 0x000D9C80, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000D9C80
{
public:
    int sub_000D9C80(float a1, int a2);
    int m_Field00; // +0x00
};

int Class_000D9C80::sub_000D9C80(float a1, int a2)
{
    int t1;

    t1 = m_Field00;
    *(float*)(m_Field00 + (a2 * 4)) = a1;
    return t1;
}
