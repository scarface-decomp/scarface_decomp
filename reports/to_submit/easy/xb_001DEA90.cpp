// bin: xb
// va: 0x001DEA90
// tool: the portal's starter code (no AI)
// sub_001DEA90 (0x001DEA90, 87 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001DE640(int);
};

extern "C" int __cdecl sub_0002FAD0(int, int);

class Class_001DEA90
{
public:
    void sub_001DEA90();
    char m_pad00[0x90];
    int m_Field90; // +0x90
    int m_Field94; // +0x94
};

void Class_001DEA90::sub_001DEA90()
{
    int r_eax, r_esi;

    r_eax = m_Field94;
    if (r_eax > 0) goto L_55;
    r_eax = sub_0002FAD0(0, (m_Field90 - r_eax) - 1);
    r_esi = 0;
    do {
        if (!*(bool*)((int)this + r_esi + 140)) {
            r_eax -= 1;
            if (r_eax < 0) goto L_3B;
        }
        r_esi += 1;
    } while (r_esi < 4);
    return;
L_3B:
    ((Object*)*(int*)((int)this + (r_esi * 4) + 124))->sub_001DE640(8);
    *(bool*)(r_esi + (int)this + 140) = true;
    m_Field94 += 1;
L_55:
    ;
}
