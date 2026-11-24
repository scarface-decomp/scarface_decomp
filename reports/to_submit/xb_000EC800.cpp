// bin: xb
// va: 0x000EC800
// what: Fetches the singleton from sub_000EB680 and calls sub_000EB690(0x56, 0) on it.
// tool: Gemini 4 Neon

struct Singleton_000EB680
{
    void sub_000EB690(int a1, int a2);
};

extern "C" Singleton_000EB680* __cdecl sub_000EB680();

void __cdecl sub_000EC800()
{
    sub_000EB680()->sub_000EB690(0x56, 0);
}
