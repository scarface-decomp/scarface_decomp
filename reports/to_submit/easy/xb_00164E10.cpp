// bin: xb
// va: 0x00164E10
// tool: the portal's starter code (no AI)
// sub_00164E10 (0x00164E10, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1AC
{
    int sub_000D18F0(int);
};

extern "C" int __cdecl sub_0002F870(int);

class Class_00164E10
{
public:
    int sub_00164E10(int a1);
    char m_pad00[0x1AC];
    Field1AC* m_Field1AC; // +0x1AC
};

int Class_00164E10::sub_00164E10(int a1)
{
    return sub_0002F870(m_Field1AC->sub_000D18F0(a1));
}
