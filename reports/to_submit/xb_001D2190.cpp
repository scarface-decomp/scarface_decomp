// bin: xb
// va: 0x001D2190
// what: 
// tool: the portal's starter code (no AI)

// sub_001D2190 (0x001D2190, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00048750(int);

class Class_001D2190
{
public:
    void sub_001D2190();
    char m_pad00[0xA8];
    int m_FieldA8; // +0xA8
};

void Class_001D2190::sub_001D2190()
{
    int t1;

    t1 = m_FieldA8;
    if (m_FieldA8) {
        sub_00048750(t1);
    }
}
