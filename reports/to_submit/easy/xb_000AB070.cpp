// bin: xb
// va: 0x000AB070
// tool: the portal's starter code (no AI)
// sub_000AB070 (0x000AB070, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000AB070
{
public:
    int sub_000AB070();
    char m_pad00[0x14];
    int m_Field14; // +0x14
};

int Class_000AB070::sub_000AB070()
{
    return m_Field14 != 0;
}
