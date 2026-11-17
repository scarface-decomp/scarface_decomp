// bin: proto
// va: 0x001A6A20
// tool: the portal's starter code (no AI)
// sub_001A6A20 (0x001A6A20, 90 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001A64D0(int);
};

extern "C" int __cdecl sub_0002CCB0(int, int);

class Class_001A6A20
{
public:
    void sub_001A6A20();
    char m_pad00[0x94];
    int m_Field94; // +0x94
    int m_Field98; // +0x98
};

void Class_001A6A20::sub_001A6A20()
{
    int r_eax, r_esi;

    r_eax = m_Field98;
    if (r_eax > 0) goto L_58;
    r_eax = sub_0002CCB0(0, (m_Field94 - r_eax) - 1);
    r_esi = 0;
    do {
        if (!*(bool*)((int)this + r_esi + 144)) {
            r_eax -= 1;
            if (r_eax < 0) goto L_3B;
        }
        r_esi += 1;
    } while (r_esi < 4);
    return;
L_3B:
    ((Object*)*(int*)((int)this + (r_esi * 4) + 128))->sub_001A64D0(8);
    *(bool*)(r_esi + (int)this + 144) = true;
    m_Field98 += 1;
L_58:
    ;
}
