// bin: xb
// va: 0x000D8070
// what: Returns the 16-bit field at +0x02 if the argument equals 2, otherwise returns 0xFFFF.
// tool: Gemini 4 Neon

class Class_000D8070
{
public:
    unsigned short sub_000D8070(int kind);
    char m_pad00[0x2];
    unsigned short m_Field02; // +0x02
};

unsigned short Class_000D8070::sub_000D8070(int kind)
{
    if (kind == 2) {
        return m_Field02;
    }
    return 0xFFFF;
}
