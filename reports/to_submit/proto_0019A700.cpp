// bin: proto
// va: 0x0019A700
// what: 
// tool: the portal's starter code (no AI)

// sub_0019A700 (Proto 0x0019A700, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00041460(int);

class Class_0019A700
{
public:
    void sub_0019A700();
    char m_pad00[0xA0];
    int m_FieldA0; // +0xA0
};

void Class_0019A700::sub_0019A700()
{
    int t1;

    t1 = m_FieldA0;
    if (m_FieldA0) {
        sub_00041460(t1);
    }
}
