// bin: xb
// va: 0x00283F50
// what: Starts a new system thread that will run the given function: fills in its record, creates it suspended, sets its priority and lets it go.
// tool: Claude (from SPEC-018)

struct Thread;

// One fiber of a thread (0x24 bytes).
struct Fiber
{
    int (__cdecl* m_Entry)(void* argument);     // +0x00
    void* m_Argument;       // +0x04
    Thread* m_Owner;        // +0x08
    Fiber* m_Next;          // +0x0C
    Fiber* m_Previous;      // +0x10
    void* m_SystemFiber;    // +0x14
    int m_Field18;          // +0x18
    int m_Field1C;          // +0x1C
    int m_Field20;          // +0x20
};

// A thread's record (0x4C bytes). Its first fiber is part of it.
struct Thread
{
    Thread* m_Next;         // +0x00
    Thread* m_Previous;     // +0x04
    Fiber m_FirstFiber;     // +0x08
    Fiber* m_CurrentFiber;  // +0x2C
    Fiber* m_FiberHead;     // +0x30
    Fiber* m_FiberTail;     // +0x34
    bool m_Running;         // +0x38
    int m_Result;           // +0x3C
    int m_Priority;         // +0x40
    unsigned int m_Id;      // +0x44
    void* m_Handle;         // +0x48
};

extern "C" int DAT_0045B0AC[5];     // the system priority for each of the library's five priorities
extern "C" void* __stdcall CreateThread(void* security, unsigned int stackSize, unsigned int (__stdcall* start)(Thread*), void* parameter, unsigned int flags, unsigned int* id);
extern "C" int __stdcall SetThreadPriority(void* handle, int priority);
extern "C" unsigned int __stdcall sub_002345F9(void* handle);  // ResumeThread
extern "C" unsigned int __stdcall sub_00283E70(Thread* thread); // what the new thread runs first
void __cdecl sub_00283BF0(Thread* thread);                      // adds it to the list of all threads

// Adds a fiber to the end of its thread's list of fibers.
inline void AppendFiber(Thread* thread, Fiber* fiber)
{
    if (thread->m_FiberHead == 0)
    {
        thread->m_FiberHead = fiber;
        fiber->m_Previous = 0;
    }
    else
    {
        thread->m_FiberTail->m_Next = fiber;
        fiber->m_Previous = thread->m_FiberTail;
    }
    thread->m_FiberTail = fiber;
    fiber->m_Next = 0;
}

// Records the thread's priority (0 to 4) and gives the system thread the matching system priority.
inline void SetPriority(Thread* thread, int priority)
{
    thread->m_Priority = priority;
    SetThreadPriority(thread->m_Handle, DAT_0045B0AC[priority]);
}

void __cdecl sub_00283F50(Thread* thread, int (__cdecl* entry)(void*), void* argument, int priority, unsigned int stackSize)
{
    thread->m_FiberHead = 0;
    thread->m_FiberTail = 0;
    thread->m_Running = true;
    thread->m_CurrentFiber = &thread->m_FirstFiber;
    thread->m_FirstFiber.m_Field20 = 0;
    thread->m_FirstFiber.m_Entry = entry;
    thread->m_FirstFiber.m_Argument = argument;
    thread->m_FirstFiber.m_Owner = thread;
    thread->m_FirstFiber.m_SystemFiber = 0;
    thread->m_FirstFiber.m_Field18 = 0;
    thread->m_FirstFiber.m_Field1C = 0;
    AppendFiber(thread, &thread->m_FirstFiber);
    sub_00283BF0(thread);
    thread->m_Handle = CreateThread(0, stackSize, sub_00283E70, thread, 4, &thread->m_Id);
    thread->m_FirstFiber.m_Field1C = 0;
    SetPriority(thread, priority);
    sub_002345F9(thread->m_Handle);
}
