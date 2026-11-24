// bin: xb
// va: 0x000CBC70
// what: Returns true if the 32-bit field at +0x9C of the object pointed to by +0xAC is non-zero.
// tool: Gemini 4 Neon

struct FieldAC_000CBC70
{
    char m_pad00[0x9C];
    int m_Field9C; // +0x9C
};

class Class_000CBC70
{
public:
    bool sub_000CBC70();
    char m_pad00[0xAC];
    FieldAC_000CBC70* m_FieldAC; // +0xAC
};

bool Class_000CBC70::sub_000CBC70()
{
    return m_FieldAC->m_Field9C != 0;
}
