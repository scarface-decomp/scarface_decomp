// bin: xb
// va: 0x0002B750
// tool: the portal's starter code (no AI)
// sub_0002B750 (0x0002B750, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0002B420(void);

class Class_0002B750
{
public:
    void sub_0002B750(int a1);
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    char m_pad10[0xE];
    unsigned char m_Field1E; // +0x1E
};

void Class_0002B750::sub_0002B750(int a1)
{
    m_Field0C = a1;
    if (m_Field1E & 2) {
        sub_0002B420();
    }
}
