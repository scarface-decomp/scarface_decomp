// bin: proto
// va: 0x00148060
// what: Runs an update on the part of this object at +0x2C0 when it is set.
// tool: Claude Opus 5.5 (transplanted from xb:0x00164530, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00155EF0();
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
    int r_eax;

    r_eax = m_Field2C0;
    if (r_eax) {
        ((Object*)(int)this + 704)->sub_00155EF0();
    }
}