// bin: proto
// va: 0x0003BE40
// tool: the portal's starter code (no AI)
// sub_0003BE40 (0x0003BE40, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field78
{
    void sub_001FEE40(int);
};

struct Object
{
    void sub_001FEEB0(int);
};

class Class_0003BE40
{
public:
    void sub_0003BE40();
    char m_pad00[0x30];
    int m_Field30; // +0x30
    char m_pad34[0x44];
    Field78 m_Field78; // +0x78
};

void Class_0003BE40::sub_0003BE40()
{
    int r_ebx, r_edi, r_esi;

    r_ebx = 0;
    do {
        r_esi = *(int*)(r_ebx + m_Field30);
        if (r_esi) {
            do {
                r_edi = *(int*)r_esi;
                if (!*(int*)(r_esi + 92)) {
                    ((Object*)m_Field30 + r_ebx)->sub_001FEEB0(r_esi);
                    m_Field78.sub_001FEE40(r_esi);
                }
                r_esi = r_edi;
            } while (r_edi);
        }
        r_ebx += 12;
    } while (r_ebx < 684);
}
