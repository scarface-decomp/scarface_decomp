// bin: proto
// va: 0x0003C070
// what: 
// tool: the portal's starter code (no AI)

// sub_0003C070 (Proto 0x0003C070, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_0003BE90(int);
};

class Class_0003C070
{
public:
    void sub_0003C070(bool a1);
    char m_pad00[0x10];
    Field10* m_Field10; // +0x10
    bool m_Field14; // +0x14
    bool m_Field15; // +0x15
};

void Class_0003C070::sub_0003C070(bool a1)
{
    m_Field14 = a1;
    if (m_Field10) {
        if (!m_Field15) goto L_26;
        if (a1) goto L_26;
        m_Field10->sub_0003BE90((int)this);
        m_Field15 = false;
    }
L_26:
    ;
}
