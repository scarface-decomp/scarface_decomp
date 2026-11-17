// bin: proto
// va: 0x0009F970
// tool: the portal's starter code (no AI)
// sub_0009F970 (0x0009F970, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

class Class_0009F970
{
public:
    int sub_0009F970();
    char m_pad00[0x8];
    int m_Field08; // +0x08
};

int Class_0009F970::sub_0009F970()
{
    return sub_00028120(m_Field08);
}
