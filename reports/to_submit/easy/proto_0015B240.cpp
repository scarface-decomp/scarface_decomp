// bin: proto
// va: 0x0015B240
// tool: the portal's starter code (no AI)
// sub_0015B240 (0x0015B240, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

class Class_0015B240
{
public:
    int sub_0015B240();
    char m_pad00[0x4];
    int m_Field04; // +0x04
};

int Class_0015B240::sub_0015B240()
{
    return sub_00028120(m_Field04);
}
