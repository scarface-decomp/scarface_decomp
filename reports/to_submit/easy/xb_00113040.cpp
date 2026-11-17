// bin: xb
// va: 0x00113040
// tool: the portal's starter code (no AI)
// sub_00113040 (0x00113040, 14 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00113040
{
public:
    int sub_00113040();
    char m_pad00[0x80];
    int m_Field80; // +0x80
};

int Class_00113040::sub_00113040()
{
    return m_Field80 != 0;
}
