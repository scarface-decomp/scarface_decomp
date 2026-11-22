// bin: proto
// va: 0x0012D210
// what: 
// tool: the portal's starter code (no AI)

// sub_0012D210 (Proto 0x0012D210, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

class Class_0012D210
{
public:
    void sub_0012D210(int a1);
    char m_pad00[0x2C];
    int m_Field2C; // +0x2C
    char m_pad30[0x18];
    int m_Field48; // +0x48
    char m_pad4C[0x17];
    unsigned char m_Field63; // +0x63
};

void Class_0012D210::sub_0012D210(int a1)
{
    if (!m_Field63) {
        if (!sub_00028120(m_Field48)) {
            *(int*)(m_Field2C + 48) = 1;
            m_Field63 = 1;
            return;
        }
        m_Field63 = (unsigned char)(*(bool*)(m_Field2C + 109) & 1);
    }
}
