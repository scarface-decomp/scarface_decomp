// bin: proto
// va: 0x001BF9F0
// what: Passes the object held at +0x74 to a helper when there is one.
// tool: Claude Opus 5.5 (transplanted from xb:0x000B8540, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00015510(int);

class Class_001BF9F0
{
public:
    void sub_001BF9F0();
    char m_pad00[0x74];
    int m_Field74; // +0x74
};

void Class_001BF9F0::sub_001BF9F0()
{
    int r_eax;

    r_eax = m_Field74;
    if (r_eax) {
        r_eax = sub_00015510(r_eax);
    }
    return;
}