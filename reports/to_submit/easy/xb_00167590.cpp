// bin: xb
// va: 0x00167590
// tool: the portal's starter code (no AI)
// sub_00167590 (0x00167590, 48 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0048A9D8;

class Class_00167590
{
public:
    int sub_00167590();
    char m_pad00[0x422];
    bool m_Field422; // +0x422
};

int Class_00167590::sub_00167590()
{
    int t1, t2;

    if (!m_Field422) {
        t1 = DAT_0048A9D8;
        if (!DAT_0048A9D8) goto L_2A;
        t2 = *(int*)(t1 + 180);
        if (*(int*)(t1 + 180)) {
            if (*(bool*)(t2 + 168)) goto L_2A;
        }
        return 0;
    }
L_2A:
    return 1;
}
