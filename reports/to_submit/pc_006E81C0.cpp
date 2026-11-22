// bin: pc
// va: 0x006E81C0
// what: Stores a yes/no value at +0xB0, then runs a step on the part of this object at +0xAC.
// tool: Claude Opus 5.5 (transplanted from proto:0x00285220, nearest by portal/tools/similar.py)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_006DF0D0(int);

class Class_006E81C0
{
public:
    void sub_006E81C0(bool a1);
    char m_pad00[0xB0];
    bool m_FieldB0; // +0xB0
};

void Class_006E81C0::sub_006E81C0(bool a1)
{
    m_FieldB0 = a1;
    sub_006DF0D0((int)this + 172);
}