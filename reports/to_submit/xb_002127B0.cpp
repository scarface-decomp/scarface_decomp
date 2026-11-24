// bin: xb
// va: 0x002127B0
// what: 
// tool: the portal's starter code (no AI)

// sub_002127B0 (0x002127B0, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00096850(int);
};

class Class_002127B0
{
public:
    void sub_002127B0(int a1);
    char m_pad00[0x20];
    int m_Field20; // +0x20
};

void Class_002127B0::sub_002127B0(int a1)
{
    int t1;

    t1 = m_Field20;
    if (m_Field20) {
        ((Object*)t1)->sub_00096850(a1);
        return;
    }
}
