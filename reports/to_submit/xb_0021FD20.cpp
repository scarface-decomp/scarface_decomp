// bin: xb
// va: 0x0021FD20
// what: Returns whether bit 0 of the global flag byte DAT_0049153F is set.
// tool: Gemini 4 Neon

struct Flags_0049153F
{
    unsigned char m_Bit0 : 1;
};

extern "C" Flags_0049153F DAT_0049153F;

bool __cdecl sub_0021FD20()
{
    return DAT_0049153F.m_Bit0;
}
