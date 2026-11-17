// bin: pc
// va: 0x006EB350
// tool: the portal's starter code (no AI)
// sub_006EB350 (0x006EB350, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006EB350
{
public:
    int sub_006EB350();
    char m_pad00[0x280];
    int m_Field280; // +0x280
};

int Class_006EB350::sub_006EB350()
{
    return *(int*)(((m_Field280 + 8) << 4) + (int)this);
}
