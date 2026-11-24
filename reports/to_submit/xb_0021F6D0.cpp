// bin: xb
// va: 0x0021F6D0
// what: Returns whether flag bit 4 of the global byte DAT_0049153C is set.
// tool: Gemini 4 Neon

struct Flags_0049153C
{
    unsigned char m_Bit0 : 1;
    unsigned char m_Bit1 : 1;
    unsigned char m_Bit2 : 1;
    unsigned char m_Bit3 : 1;
    unsigned char m_Bit4 : 1;
};

extern "C" Flags_0049153C DAT_0049153C;

bool __cdecl sub_0021F6D0()
{
    return DAT_0049153C.m_Bit4;
}
