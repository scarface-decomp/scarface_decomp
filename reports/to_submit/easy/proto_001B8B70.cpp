// bin: proto
// va: 0x001B8B70
// tool: the portal's starter code (no AI)
// sub_001B8B70 (0x001B8B70, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field12C
{
    void sub_001C43E0(int);
};

extern "C" int DAT_00462DD4;
extern "C" int __cdecl sub_00028120(int);

class Class_001B8B70
{
public:
    void sub_001B8B70(int a1);
    char m_pad00[0x12C];
    Field12C* m_Field12C; // +0x12C
    int m_Field130; // +0x130
};

void Class_001B8B70::sub_001B8B70(int a1)
{
    if (*(int*)(sub_00028120(m_Field130) + 16) == DAT_00462DD4) {
        m_Field12C->sub_001C43E0(a1);
    }
}
