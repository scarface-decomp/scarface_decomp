// bin: xb
// va: 0x002CE350
// tool: the portal's starter code (no AI)
// sub_002CE350 (0x002CE350, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_002CE350
{
public:
    void sub_002CE350(int a1);
    char m_pad00[0x8];
    unsigned short m_Field08; // +0x08
};

void Class_002CE350::sub_002CE350(int a1)
{
    m_Field08 = (unsigned short)a1;
}
