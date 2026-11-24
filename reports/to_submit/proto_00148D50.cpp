// bin: proto
// va: 0x00148D50
// what: 
// tool: the portal's starter code (no AI)

// sub_00148D50 (Proto 0x00148D50, 44 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_000F75D0();
};

extern "C" int __cdecl sub_00028120(int);

class Class_00148D50
{
public:
    int sub_00148D50();
    char m_pad00[0xDC];
    int m_FieldDC; // +0xDC
};

int Class_00148D50::sub_00148D50()
{
    int t2;

    t2 = sub_00028120(m_FieldDC);
    if (t2) {
        if (((Object*)t2 + 1468)->sub_000F75D0() < 3) goto L_29;
        return 1;
    }
L_29:
    return 0;
}
