// bin: xb
// va: 0x001F0540
// what: Copies a three-number value (such as a colour) into a global setting.
// tool: Claude Opus 5.5 (symcov hint: R_SetFogColor(const Color *), link-order)
// sub_001F0540 (0x001F0540, 43 bytes)

struct Struct_001F0540
{
    float m_Field00; // +0x00
    float m_Field04; // +0x04
    float m_Field08; // +0x08
};

extern "C" Struct_001F0540 DAT_0043EBC4;

// Stores the three components in the global.
void __cdecl sub_001F0540(const Struct_001F0540 *value)
{
    DAT_0043EBC4.m_Field00 = value->m_Field00;
    DAT_0043EBC4.m_Field04 = value->m_Field04;
    DAT_0043EBC4.m_Field08 = value->m_Field08;
}
