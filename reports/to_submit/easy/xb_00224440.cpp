// bin: xb
// va: 0x00224440
// tool: the portal's starter code (no AI)
// sub_00224440 (0x00224440, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00224440
{
public:
    bool sub_00224440(int a1);
    float m_Field00; // +0x00
    char m_pad04[0x4];
    float m_Field08; // +0x08
    char m_pad0C[0x10];
    float m_Field1C; // +0x1C
};

bool Class_00224440::sub_00224440(int a1)
{
    float t1, t2, t3, t4;

    t1 = *(float*)a1;
    t2 = *(float*)(a1 + 8);
    t3 = m_Field1C;
    t4 = t1 - m_Field00;
    if (((t4 * (t1 - m_Field00)) + ((t2 - m_Field08) * (t2 - m_Field08))) > (t3 * t3)) {
        return true;
    }
    return false;
}
