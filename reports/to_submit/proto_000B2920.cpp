// bin: proto
// va: 0x000B2920
// what: Frees the buffers this object holds and clears their pointers, when it has any entries.
// tool: Claude Opus 5.5 (transplanted from xb:0x000C02A0, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00025160(int);

class Class_000B2920
{
public:
    void sub_000B2920();
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    char m_pad0C[0x1C];
    int m_Field28; // +0x28
};

void Class_000B2920::sub_000B2920()
{
    int r_eax;

    r_eax = 0;
    if (m_Field00 > 0) {
        r_eax = m_Field28;
        if (r_eax) {
            sub_00025160(r_eax);
            m_Field28 = 0;
        }
        r_eax = m_Field04;
        if (r_eax) {
            sub_00025160(r_eax);
            m_Field04 = 0;
        }
        r_eax = m_Field08;
        if (r_eax) {
            r_eax = sub_00025160(r_eax);
            m_Field08 = 0;
        }
        m_Field00 = 0;
    }
    return;
}