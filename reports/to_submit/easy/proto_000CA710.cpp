// bin: proto
// va: 0x000CA710
// tool: the portal's starter code (no AI)
// sub_000CA710 (0x000CA710, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000CA710
{
public:
    int sub_000CA710();
    char m_pad00[0x20];
    int m_Field20; // +0x20
};

int Class_000CA710::sub_000CA710()
{
    return m_Field20 != 0;
}
