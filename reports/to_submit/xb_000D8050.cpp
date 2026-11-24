// bin: xb
// va: 0x000D8050
// what: Stores the 16-bit second argument at +0x02 if the first argument equals 2.
// tool: Gemini 4 Neon

class Class_000D8050
{
public:
    void sub_000D8050(int kind, unsigned short value);
    char m_pad00[0x2];
    unsigned short m_Field02; // +0x02
};

void Class_000D8050::sub_000D8050(int kind, unsigned short value)
{
    if (kind == 2) {
        m_Field02 = value;
    }
}
