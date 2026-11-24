// bin: xb
// va: 0x001631A0
// what: 
// tool: the portal's starter code (no AI)

// sub_001631A0 (0x001631A0, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001631A0
{
public:
    bool sub_001631A0(bool a1);
    char m_pad00[0x420];
    bool m_Field420; // +0x420
};

bool Class_001631A0::sub_001631A0(bool a1)
{
    m_Field420 = a1;
    return a1;
}
