// bin: xb
// va: 0x000E7580
// tool: the portal's starter code (no AI)
// sub_000E7580 (0x000E7580, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000E7580
{
public:
    bool sub_000E7580(float a1);
    char m_pad00[0x28];
    float m_Field28; // +0x28
};

bool Class_000E7580::sub_000E7580(float a1)
{
    m_Field28 = a1;
    return true;
}
