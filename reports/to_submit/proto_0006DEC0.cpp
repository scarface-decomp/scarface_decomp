// bin: proto
// va: 0x0006DEC0
// what: Sets up the object, registers it, and records the sizes 36 and 4 in it.
// tool: Claude Opus 5.5 (transplanted from proto:0x00077EA0, nearest by portal/tools/similar.py)
struct Object
{
    int sub_002CA6F2();
};

extern "C" Object DAT_003FD43C;

class Class_0006DEC0
{
public:
    Class_0006DEC0* sub_0006DEC0();
    void sub_00290E20(int, int);
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

Class_0006DEC0* Class_0006DEC0::sub_0006DEC0()
{
    int val = DAT_003FD43C.sub_002CA6F2();
    sub_00290E20(val, 0);
    m_Field0C = 36;
    m_Field10 = 4;
    return this;
}