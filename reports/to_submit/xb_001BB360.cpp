// bin: xb
// va: 0x001BB360
// what: Calls sub_001BB290(2, 1, 0) and returns whether its byte result is non-zero.
// tool: Gemini 4 Neon

class Class_001BB360
{
public:
    unsigned char sub_001BB360();
    unsigned char sub_001BB290(int a1, int a2, int a3);
};

unsigned char Class_001BB360::sub_001BB360()
{
    return sub_001BB290(2, 1, 0) != 0;
}
