// bin: proto
// va: 0x00148690
// tool: the portal's starter code (no AI)
// sub_00148690 (0x00148690, 39 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000C6900();
};

class Class_00148690
{
public:
    bool sub_00148690();
    char m_pad00[0x188];
    int m_Field188; // +0x188
};

bool Class_00148690::sub_00148690()
{
    int t1, t2;

    t1 = m_Field188;
    if (m_Field188) {
        t2 = *(int*)(t1 + 384);
        if (!*(int*)(t1 + 384)) goto L_24;
        return ((Object*)t2)->sub_000C6900() == 3;
    }
L_24:
    return false;
}
