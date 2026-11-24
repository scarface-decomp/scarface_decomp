// bin: xb
// va: 0x000EC710
// what: Fetches the singleton from sub_000EB680 and calls sub_000EC0F0(0x57, a1, 0) on it.
// tool: Gemini 4 Neon

struct Singleton_000EB680
{
    void sub_000EC0F0(int id, int value, int mode);
};

extern "C" Singleton_000EB680* __cdecl sub_000EB680();

void __cdecl sub_000EC710(int value)
{
    sub_000EB680()->sub_000EC0F0(0x57, value, 0);
}
