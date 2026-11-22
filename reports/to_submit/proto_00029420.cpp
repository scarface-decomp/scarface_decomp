// bin: proto
// va: 0x00029420
// what: 
// tool: the portal's starter code (no AI)

// sub_00029420 (Proto 0x00029420, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0006C370(int, int);

class Class_00029420
{
public:
    void sub_00029420(int a1);
    void sub_00028C40(int);
    char m_pad00[0x8];
    int m_Field08; // +0x08
    char m_pad0C[0x12];
    unsigned char m_Field1E; // +0x1E
};

void Class_00029420::sub_00029420(int a1)
{
    if (a1) {
        if (!*(unsigned char*)a1) goto L_1E;
        m_Field08 = sub_0006C370(a1, 0);
    }
L_1E:
    if (m_Field1E & 2) {
        sub_00028C40(0);
    }
}
