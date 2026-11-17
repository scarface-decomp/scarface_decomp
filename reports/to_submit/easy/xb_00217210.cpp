// bin: xb
// va: 0x00217210
// tool: the portal's starter code (no AI)
// sub_00217210 (0x00217210, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_000AC800(int);
};

class Class_00217210
{
public:
    bool sub_00217210(int a1);
    char m_pad00[0x44];
    bool m_Field44; // +0x44
};

bool Class_00217210::sub_00217210(int a1)
{
    if (m_Field44) {
        return ((Object*)(int)this + 72)->sub_000AC800(a1);
    }
    return false;
}
