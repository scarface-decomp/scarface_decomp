// bin: proto
// va: 0x000B9880
// tool: the portal's starter code (no AI)
// sub_000B9880 (0x000B9880, 93 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field34
{
    int sub_000B8830();
    int sub_000B8870(int);
};

struct Object
{
    void sub_0018F470();
};

extern "C" char DAT_00384A4C[];
extern "C" int __stdcall sub_0018ED90(int, int, int, int, int, int, int);

class Class_000B9880
{
public:
    void sub_000B9880(int a1);
    void sub_000B9670(int, int, int);
    char m_pad00[0x34];
    Field34* m_Field34; // +0x34
    char m_pad38[0x24];
    int m_Field5C; // +0x5C
    char m_pad60[0xA];
    bool m_Field6A; // +0x6A
};

void Class_000B9880::sub_000B9880(int a1)
{
    if (!m_Field34->sub_000B8830()) {
        if (m_Field34->sub_000B8870(m_Field5C)) goto L_4A;
        if (!m_Field6A) goto L_59;
        ((Object*)sub_0018ED90(a1, 1, 16, 0, 0, 0, (int)DAT_00384A4C))->sub_0018F470();
        return;
    }
L_4A:
    sub_000B9670(m_Field5C, 0, 1);
L_59:
    ;
}
