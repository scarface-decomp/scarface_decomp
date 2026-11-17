// bin: xb
// va: 0x00094C40
// tool: the portal's starter code (no AI)
// sub_00094C40 (0x00094C40, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003A440C[];
extern "C" int __cdecl sub_00244040(int, int);

class Class_00094C40
{
public:
    Class_00094C40* sub_00094C40(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

Class_00094C40* Class_00094C40::sub_00094C40(int a1)
{
    m_Field00 = (int)DAT_003A440C;
    if (a1) {
        if (!*(unsigned char*)a1) goto L_24;
        m_Field04 = sub_00244040(a1, 0);
    }
L_24:
    return this;
}
