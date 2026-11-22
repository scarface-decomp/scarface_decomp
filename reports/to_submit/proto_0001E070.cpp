// bin: proto
// va: 0x0001E070
// what: 
// tool: the portal's starter code (no AI)

// sub_0001E070 (Proto 0x0001E070, 54 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00025160(int);

class Class_0001E070
{
public:
    void sub_0001E070();
    void sub_00031F20();
    char m_pad00[0x1B];
    unsigned char m_Field1B; // +0x1B
    int m_Field1C; // +0x1C
};

void Class_0001E070::sub_0001E070()
{
    if (m_Field1B == 2) {
        sub_00025160(m_Field1C);
    }
    if (m_Field1B == 3) {
        sub_00025160(m_Field1C);
    }
    sub_00031F20();
    sub_00031F20();
}
