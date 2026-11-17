// bin: xb
// va: 0x000BC9D0
// tool: the portal's starter code (no AI)
// sub_000BC9D0 (0x000BC9D0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039DD50;

class Class_000BC9D0
{
public:
    int sub_000BC9D0();
    char m_pad00[0xDC];
    float m_FieldDC; // +0xDC
};

int Class_000BC9D0::sub_000BC9D0()
{
    if (DAT_0039DD50 > m_FieldDC) {
        return 1;
    }
    return 0;
}
