// bin: proto
// va: 0x000DD880
// what: The first time only: sets a flag, stores the yes/no value given, and copies a number from a global object.
// tool: Claude Opus 5.5 (transplanted from xb:0x000F1000, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_0045A0EC;

class Class_000DD880
{
public:
    void sub_000DD880(bool a1);
    char m_pad00[0x408];
    int m_Field408; // +0x408
    char m_pad40C[0x1F3];
    bool m_Field5FF; // +0x5FF
    bool m_Field600; // +0x600
};

void Class_000DD880::sub_000DD880(bool a1)
{
    int r_eax;

    r_eax = m_Field5FF;
    if (!((unsigned char)r_eax)) {
        r_eax = a1;
        m_Field5FF = true;
        m_Field600 = a1;
        r_eax = *(int*)(DAT_0045A0EC + 44);
        m_Field408 = r_eax;
    }
}