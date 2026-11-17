// bin: proto
// va: 0x0029E540
// tool: the portal's starter code (no AI)
// sub_0029E540 (0x0029E540, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __stdcall sub_0029E150(int);

class Class_0029E540
{
public:
    void sub_0029E540(int a1);
    void sub_0029E2E0(int);
    char m_pad00[0x28];
    bool m_Field28; // +0x28
};

void Class_0029E540::sub_0029E540(int a1)
{
    int t1;

    if (m_Field28) {
        m_Field28 = false;
        if (a1) {
            t1 = sub_0029E150((int)(&a1));
            if (!t1) goto L_30;
            sub_0029E2E0(t1);
        }
        m_Field28 = true;
    }
L_30:
    ;
}
