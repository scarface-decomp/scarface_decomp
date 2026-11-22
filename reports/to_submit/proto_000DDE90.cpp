// bin: proto
// va: 0x000DDE90
// what: 
// tool: the portal's starter code (no AI)

// sub_000DDE90 (Proto 0x000DDE90, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field440
{
    int sub_00056450();
    bool sub_000ED6E0();
};

class Class_000DDE90
{
public:
    int sub_000DDE90(int a1);
    char m_pad00[0x440];
    Field440 m_Field440; // +0x440
    char m_pad441[0x1C0];
    bool m_Field601; // +0x601
};

int Class_000DDE90::sub_000DDE90(int a1)
{
    if (!m_Field440.sub_000ED6E0()) {
        if (m_Field601) goto L_36;
        if (m_Field440.sub_00056450() != a1) goto L_36;
        return 1;
    }
L_36:
    return 0;
}
