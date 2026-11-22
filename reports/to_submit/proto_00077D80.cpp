// bin: proto
// va: 0x00077D80
// what: Sets up the object, registers it, and records the sizes 64 and 4 in it.
// tool: Claude Opus 5.5 (transplanted from proto:0x00077EA0, nearest by portal/tools/similar.py)
struct Object
{
    int sub_002CA6F2();
};

extern "C" Object DAT_003FD860;

class Class_00077D80
{
public:
    Class_00077D80* sub_00077D80();
    void sub_00290E20(int, int);
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

Class_00077D80* Class_00077D80::sub_00077D80()
{
    int val = DAT_003FD860.sub_002CA6F2();
    sub_00290E20(val, 0);
    m_Field0C = 64;
    m_Field10 = 4;
    return this;
}