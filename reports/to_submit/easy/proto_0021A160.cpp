// bin: proto
// va: 0x0021A160
// tool: the portal's starter code (no AI)
// sub_0021A160 (0x0021A160, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CD94;

class Class_0021A160
{
public:
    float sub_0021A160();
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
};

float Class_0021A160::sub_0021A160()
{
    int r_eax;

    r_eax = m_Field0C;
    if (r_eax) {
        return *(float*)(r_eax + 388);
    }
    return DAT_0037CD94;
}
