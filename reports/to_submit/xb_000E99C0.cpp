// bin: xb
// va: 0x000E99C0
// what: Sets bit 0 of the flags byte at +0x1C to the given boolean value and returns true.
// tool: Gemini 4 Neon

class Class_000E99C0
{
public:
    bool sub_000E99C0(bool value);
    char m_pad00[0x1C];
    unsigned char m_Flag0 : 1; // +0x1C
};

bool Class_000E99C0::sub_000E99C0(bool value)
{
    m_Flag0 = value;
    return true;
}
