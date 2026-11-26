// bin: xb
// va: 0x002C17B0
// what: Takes the next request off the drive thread's queues, highest priority first and skipping held ones, and makes it the current request.
// tool: Claude (from SPEC-018)

// A system semaphore's handle.
struct Semaphore
{
    void* m_Handle; // +0x0
};

// A thread's record (0x4C bytes); SPEC-018 part A has its fields.
struct Thread
{
    char m_pad00[0x4C];
};

void __cdecl sub_00283BC0(Semaphore* semaphore);    // wait for it
void __cdecl sub_00283BD0(Semaphore* semaphore);    // signal it once

namespace core
{
    class Drive;

    // A piece of work queued for a drive.
    class Request
    {
    public:
        virtual ~Request();
        virtual int Do();                       // does the work: 0 error, 1 done, 2 more to do
        virtual bool ShouldCancel(int key);
        virtual Drive* GetDrive();
        virtual int Prepare();                  // gets ready again after an error; same results as Do
        virtual void vfunc_05();
        virtual void vfunc_06();

        Request* m_Next;    // +0x04
    };

    // The three base parts (SPEC-017 section 1).
    class RefCountPart
    {
    public:
        virtual void vfunc_00();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
    };

    class ObjectPart
    {
    public:
        virtual void Object00();
        void* m_Allocator;  // +0x08
    };

    class SafeRefCount
    {
    public:
        virtual void Lock();
        virtual void Unlock();
        virtual void Safe02();
        int m_RefCount;     // +0x10
    };

    // What is known about one priority while it is held back.
    struct HoldRecord
    {
        unsigned int m_Field0;      // +0x0
        unsigned int m_Field4;      // +0x4
        int m_Field8;               // +0x8
        unsigned short m_Count;     // +0xC  how many holds are on this priority
        bool m_Woken;               // +0xE  the worker was woken for it while it was held
    };

    class DriveThread : public RefCountPart, public ObjectPart, public SafeRefCount
    {
    public:
        Request* sub_002C17B0(int* priority);

        void* m_Mutex;              // +0x14
        Thread m_Thread;            // +0x18
        bool m_Stop;                // +0x64
        Semaphore m_Wake;           // +0x68  one count for every queued request
        Request* m_Head[3];         // +0x6C  the queues, one for each priority
        Request* m_Tail[3];         // +0x78
        HoldRecord m_Hold[3];       // +0x84
        unsigned int m_Swallow;     // +0xB4  wake-ups the worker must ignore
        Semaphore m_Answered;       // +0xB8  signalled when an error has been answered
        bool m_Retry;               // +0xBC  the answer: try again
        unsigned int m_Outstanding; // +0xC0  requests not finished yet
        Request* m_Current;         // +0xC4  the request being worked on
        bool m_CurrentCancelled;    // +0xC8
    };
}

core::Request* core::DriveThread::sub_002C17B0(int* priority)
{
    Request* result = 0;
    Lock();
    if (m_Swallow > 0)
    {
        --m_Swallow;
        Unlock();
        return 0;
    }
    for (unsigned int i = 0; i < 3; ++i)
    {
        if (!(m_Hold[i].m_Count > 0) && m_Head[i] != 0)
        {
            result = m_Head[i];
            if (result == m_Tail[i])
            {
                m_Tail[i] = 0;
            }
            m_Head[i] = result->m_Next;
            result->m_Next = 0;
            if (priority != 0)
            {
                *priority = i;
            }
            break;
        }
    }
    m_Current = result;
    Unlock();
    return result;
}
