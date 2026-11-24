// bin: xb
// va: 0x0021F9D0
// what: Returns bit 0 of the global flags byte at DAT_0049153C.
// tool: Gemini 4 Neon

struct Flags_0049153C
{
    unsigned char m_Bit0 : 1;
};

extern "C" Flags_0049153C DAT_0049153C;

bool __cdecl sub_0021F9D0()
{
    return DAT_0049153C.m_Bit0;
}
