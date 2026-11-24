// bin: xb
// va: 0x000185A0
// what: Returns the pointer at +0x00 offset by +0x24 if the flag at +0x0C is set, otherwise +0x0C.
// tool: Gemini 4 Neon

class Class_000185A0
{
public:
    char* sub_000185A0();
    char* m_Field00; // +0x00
    char m_pad04[0x8];
    bool m_Field0C; // +0x0C
};

char* Class_000185A0::sub_000185A0()
{
    if (m_Field0C) {
        return m_Field00 + 0x24;
    }
    return m_Field00 + 0x0C;
}
