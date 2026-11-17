// bin: proto
// va: 0x001901E0
// tool: the portal's starter code (no AI)
// sub_001901E0 (0x001901E0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0018F9D0(void);

class Class_001901E0
{
public:
    void sub_001901E0(int a1, bool a2);
    char m_pad00[0x24];
    int m_Field24; // +0x24
};

void Class_001901E0::sub_001901E0(int a1, bool a2)
{
    m_Field24 = a1;
    if (a2) {
        sub_0018F9D0();
    }
}
