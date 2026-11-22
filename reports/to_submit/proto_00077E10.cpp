// bin: proto
// va: 0x00077E10
// what: Sets up the object, registers it, and records the sizes 32 and 4 in it.
// tool: Claude Opus 5.5 (transplanted from proto:0x00077EA0, nearest by portal/tools/similar.py)
struct Object
{
    int sub_002CA6F2();
};

extern "C" Object DAT_003FD8E4;

class Class_00077E10
{
public:
    Class_00077E10* sub_00077E10();
    void sub_00290E20(int, int);
    char m_pad00[0xC];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
};

Class_00077E10* Class_00077E10::sub_00077E10()
{
    int val = DAT_003FD8E4.sub_002CA6F2();
    sub_00290E20(val, 0);
    m_Field0C = 32;
    m_Field10 = 4;
    return this;
}