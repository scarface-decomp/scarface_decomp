// bin: xb
// va: 0x001E4640
// what: 
// tool: the portal's starter code (no AI)

// sub_001E4640 (0x001E4640, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001E3FE0(void);

class Class_001E4640
{
public:
    void sub_001E4640();
    char m_pad00[0xA5];
    unsigned char m_FieldA5; // +0xA5
};

void Class_001E4640::sub_001E4640()
{
    if (m_FieldA5 & 1) {
        sub_001E3FE0();
        return;
    }
}
