// bin: xb
// va: 0x000DE350
// tool: the portal's starter code (no AI)
// sub_000DE350 (0x000DE350, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" int DAT_00487828;

class Class_000DE350
{
public:
    void sub_000DE350();
    char m_pad00[0x14];
    Field14* m_Field14; // +0x14
    char m_pad18[0x4];
    bool m_Field1C; // +0x1C
};

void Class_000DE350::sub_000DE350()
{
    m_Field14->vfunc_01();
    if (m_Field1C) {
        DAT_00487828 -= 1;
    }
}
