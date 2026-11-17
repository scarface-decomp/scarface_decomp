// bin: xb
// va: 0x00164C90
// tool: the portal's starter code (no AI)
// sub_00164C90 (0x00164C90, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1AC
{
    bool sub_000D18F0(int);
};

class Class_00164C90
{
public:
    int sub_00164C90();
    char m_pad00[0x1AC];
    Field1AC* m_Field1AC; // +0x1AC
};

int Class_00164C90::sub_00164C90()
{
    return !((unsigned char)(m_Field1AC->sub_000D18F0(65535) - 1));
}
