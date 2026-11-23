// bin: proto
// va: 0x001AB190
// what: 
// tool: the portal's starter code (no AI)

// sub_001AB190 (Proto 0x001AB190, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_001AAB20(void);

class Class_001AB190
{
public:
    void sub_001AB190();
    char m_pad00[0xA9];
    unsigned char m_FieldA9; // +0xA9
};

void Class_001AB190::sub_001AB190()
{
    if (m_FieldA9 & 1) {
        sub_001AAB20();
        return;
    }
}
