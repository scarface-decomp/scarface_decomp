// bin: xb
// va: 0x000EA460
// tool: the portal's starter code (no AI)
// sub_000EA460 (0x000EA460, 62 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00248FB0(int, int, int);

class Class_000EA460
{
public:
    void sub_000EA460(bool a1, int a2);
    char m_pad00[0x74];
    int m_Field74; // +0x74
    char m_pad78[0xFF];
    unsigned char m_Field177; // +0x177
};

void Class_000EA460::sub_000EA460(bool a1, int a2)
{
    if (a1 != m_Field177) {
        if (a1) {
            if (!a2) goto L_39;
            if (!*(unsigned char*)a2) goto L_39;
            sub_00248FB0((int)(&m_Field74), a2, 256);
        }
        m_Field177 = a1;
    }
L_39:
    ;
}
