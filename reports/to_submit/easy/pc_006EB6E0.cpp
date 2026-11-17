// bin: pc
// va: 0x006EB6E0
// tool: the portal's starter code (no AI)
// sub_006EB6E0 (0x006EB6E0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006EB6E0
{
public:
    void sub_006EB6E0(int a1);
    char m_pad00[0x8];
    unsigned short m_Field08; // +0x08
};

void Class_006EB6E0::sub_006EB6E0(int a1)
{
    m_Field08 = (unsigned short)a1;
}
