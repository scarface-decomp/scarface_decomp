// bin: proto
// va: 0x0001DFA0
// tool: the portal's starter code (no AI)
// sub_0001DFA0 (0x0001DFA0, 76 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00025160(int);
extern "C" int __cdecl sub_0008E670(int, int, int, int);

class Class_0001DFA0
{
public:
    bool sub_0001DFA0(int a1, bool a2);
    char m_pad00[0x18];
    bool m_Field18; // +0x18
    char m_pad19[0x2];
    unsigned char m_Field1B; // +0x1B
    int m_Field1C; // +0x1C
};

bool Class_0001DFA0::sub_0001DFA0(int a1, bool a2)
{
    if (m_Field1B == 2) {
        sub_00025160(m_Field1C);
    }
    if (m_Field1B == 3) {
        sub_00025160(m_Field1C);
    }
    m_Field1C = sub_0008E670(2, a1, 0, 0);
    m_Field18 = a2;
    m_Field1B = 3;
    return a2;
}
