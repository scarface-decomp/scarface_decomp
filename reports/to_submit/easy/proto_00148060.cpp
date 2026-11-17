// bin: proto
// va: 0x00148060
// tool: the portal's starter code (no AI)
// sub_00148060 (0x00148060, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00155EF0();
};

class Class_00148060
{
public:
    void sub_00148060();
    char m_pad00[0x2C0];
    int m_Field2C0; // +0x2C0
};

void Class_00148060::sub_00148060()
{
    if (m_Field2C0) {
        ((Object*)(int)this + 704)->sub_00155EF0();
        return;
    }
}
