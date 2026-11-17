// bin: proto
// va: 0x00120370
// tool: the portal's starter code (no AI)
// sub_00120370 (0x00120370, 33 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0011E4B0(void);

class Class_00120370
{
public:
    void sub_00120370(int a1);
    void sub_00120000(int);
    char m_pad00[0x12C];
    unsigned char m_Field12C; // +0x12C
};

void Class_00120370::sub_00120370(int a1)
{
    sub_0011E4B0();
    if ((unsigned int)m_Field12C > (unsigned int)1) {
        sub_00120000(a1);
    }
}
