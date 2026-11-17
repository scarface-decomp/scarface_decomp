// bin: xb
// va: 0x00071BE0
// tool: the portal's starter code (no AI)
// sub_00071BE0 (0x00071BE0, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00026F40(int);
    void sub_00026F60();
};

extern "C" int DAT_0041F0CC;
extern "C" int DAT_0041F0D0;
extern "C" void __cdecl sub_00027600(int);

class Class_00071BE0
{
public:
    void sub_00071BE0();
    char m_pad00[0x4];
    int m_Field04; // +0x04
    char m_pad08[0x4];
    unsigned char m_Field0C; // +0x0C
};

void Class_00071BE0::sub_00071BE0()
{
    int local_4;

    if (m_Field0C == 255) {
        if (m_Field04 == DAT_0041F0D0) goto L_42;
        ((Object*)(int)(&local_4))->sub_00026F40(DAT_0041F0CC);
        sub_00027600(m_Field04);
        m_Field04 = DAT_0041F0D0;
        ((Object*)(int)(&local_4))->sub_00026F60();
    }
L_42:
    ;
}
