// bin: proto
// va: 0x0009F210
// what: 
// tool: the portal's starter code (no AI)

// sub_0009F210 (Proto 0x0009F210, 50 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0009F210
{
public:
    int sub_0009F210();
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    char m_pad10[0x220];
    bool m_Field230; // +0x230
    char m_pad231[0xB];
    bool m_Field23C; // +0x23C
};

int Class_0009F210::sub_0009F210()
{
    int t1, t2;

    t1 = m_Field0C;
    if (m_Field0C) {
        t2 = *(int*)(t1 + 4);
        if (!*(int*)(t1 + 4)) goto L_2F;
        if (!*(int*)(t2 + 28)) goto L_2F;
        if (!m_Field230) goto L_2F;
        if (!m_Field23C) goto L_2F;
        return 1;
    }
L_2F:
    return 0;
}
