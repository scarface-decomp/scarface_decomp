// bin: xb
// va: 0x00283AF0
// what: Waits for a thread to stop running, giving up the rest of its time slice each time round, then returns the thread's result.
// tool: Claude (from SPEC-018 section A.4.1)

extern "C" void __stdcall sub_00235F82(unsigned int milliseconds);     // Sleep

struct Thread
{
    char m_pad00[0x38];
    bool m_Running;         // +0x38
    char m_pad39[0x3];
    int m_Result;           // +0x3C
};

// The library's own sleep (0x283AE0), expanded where it is used below.
void __cdecl sub_00283AE0(unsigned int milliseconds)
{
    sub_00235F82(milliseconds);
}

// Whether the thread is still running, handed back through a pointer. This is what keeps the loop's test
// at its top: with the member read directly the compiler turns the loop round.
inline void IsRunning(const Thread* thread, bool* running)
{
    *running = thread->m_Running;
}

int __cdecl sub_00283AF0(Thread* thread)
{
    for (;;)
    {
        bool running;
        IsRunning(thread, &running);
        if (!running)
        {
            break;
        }
        sub_00283AE0(0);
    }
    return thread->m_Result;
}
