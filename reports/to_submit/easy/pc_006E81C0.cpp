// bin: pc
// va: 0x006E81C0
// tool: the portal's starter code (no AI)
// sub_006E81C0 (0x006E81C0, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DF0D0(int);

class Class_006E81C0
{
public:
    void sub_006E81C0(bool a1);
    char m_pad00[0xB0];
    bool m_FieldB0; // +0xB0
};

void Class_006E81C0::sub_006E81C0(bool a1)
{
    m_FieldB0 = a1;
    sub_006DF0D0((int)this + 172);
}
