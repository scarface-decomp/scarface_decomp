// bin: xb
// va: 0x00212ED0
// what: 
// tool: the portal's starter code (no AI)

// sub_00212ED0 (0x00212ED0, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00212ED0
{
public:
    bool sub_00212ED0();
    char m_pad00[0x74];
    int m_Field74; // +0x74
};

bool Class_00212ED0::sub_00212ED0()
{
    int t1;

    t1 = m_Field74;
    if (m_Field74) {
        return *(int*)t1 != 4;
    }
    return false;
}
