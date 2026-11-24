// bin: proto
// va: 0x001DD0F0
// what: 
// tool: the portal's starter code (no AI)

// sub_001DD0F0 (Proto 0x001DD0F0, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0009F8C0();
    void sub_002BAB20();
};

extern "C" int DAT_00426614;

class Class_001DD0F0
{
public:
    void sub_001DD0F0();
    char m_pad00[0xA4];
    int m_FieldA4; // +0xA4
    char m_padA8[0x14];
    int m_FieldBC; // +0xBC
};

void Class_001DD0F0::sub_001DD0F0()
{
    int t1;

    if (!m_FieldA4) goto L_39;
    t1 = m_FieldBC;
    if (m_FieldBC) {
        if (!*(bool*)(t1 + 68)) goto L_38;
        *(int*)(t1 + 1588) = DAT_00426614;
        ((Object*)t1 + 72)->sub_0009F8C0();
        ((Object*)*(int*)(t1 + 112))->sub_002BAB20();
        return;
    }
L_38:
L_39:
    ;
}
