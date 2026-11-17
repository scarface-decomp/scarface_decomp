// bin: xb
// va: 0x00260B20
// tool: the portal's starter code (no AI)
// sub_00260B20 (0x00260B20, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D584;

class Class_00260B20
{
public:
    float sub_00260B20();
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
};

float Class_00260B20::sub_00260B20()
{
    int r_eax;

    r_eax = m_Field0C;
    if (r_eax) {
        return *(float*)(r_eax + 388);
    }
    return DAT_0039D584;
}
