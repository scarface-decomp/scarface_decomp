// bin: xb
// va: 0x002C18B0
// what: The drive thread's worker: waits for a request, runs it, and on an error asks the game what to do, then retries, re-queues or drops it.
// tool: Claude (from SPEC-018 section B.4.11)

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
        void DropCurrent();
        void sub_002C1480(Request* request, int priority, bool atHead);
        void sub_002C1760(Drive* drive, Request* request);
        Request* sub_002C17B0(int* priority);
        void sub_002C1850();

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

namespace core
{
    // The parts of a drive this function uses.
    class Drive
    {
    public:
        int sub_002AC3E0();                     // its last error
        void sub_002AC400(int error);           // sets its last error
        int sub_002AC550();                     // what to do about errors: 0, 1 or 2
        void sub_002AC5D0(Request* request);    // tells the game about the error
        bool sub_002AC680();
    };
}

// Forgets the request being worked on and deletes it. An inline helper with the same statements as the
// member at 0x2C1850: the compiler expands it at the first two places below and calls its own copy at the
// third, and in the game that copy is the one function at 0x2C1850 (the linker keeps one of two identical
// functions; the checker compares the copy's bytes with what is there).
inline void core::DriveThread::DropCurrent()
{
    Lock();
    Request* request = m_Current;
    m_CurrentCancelled = false;
    m_Current = 0;
    Unlock();
    delete request;
}

// Tells the game about a drive's error and waits until it has been answered (0x2C1760). Expanded at two
// places below.
void core::DriveThread::sub_002C1760(Drive* drive, Request* request)
{
    drive->sub_002AC5D0(request);
    sub_00283BC0(&m_Answered);
}

// Whether the worker has been told to stop, handed back through a pointer: this keeps the loop's test in
// its place (as in 0x283AF0).
inline void IsStopped(const core::DriveThread* thread, bool* stop)
{
    *stop = thread->m_Stop;
}

int __cdecl sub_002C18B0(core::DriveThread* parent)
{
    int priority;
    bool errorRetry = false;
    for (;;)
    {
        sub_00283BC0(&parent->m_Wake);
        bool stop;
        IsStopped(parent, &stop);
        if (stop)
        {
            return 0;
        }
        core::Request* request = parent->sub_002C17B0(&priority);
        if (request == 0)
        {
            continue;
        }
        core::Drive* drive = request->GetDrive();
        int status;
        int error = drive->sub_002AC3E0();
        if (error != 0 && error != 1)
        {
            status = request->Prepare();
            if (status == 1)
            {
                status = request->Do();
            }
        }
        else
        {
            status = request->Do();
        }
        if (errorRetry == true && drive->sub_002AC3E0() == 0 && drive->sub_002AC550() == 2 && drive->sub_002AC680() == true)
        {
            parent->sub_002C1760(drive, request);
            errorRetry = false;
        }
        switch (status)
        {
        case 2:
            if (parent->m_CurrentCancelled)
            {
                parent->DropCurrent();
            }
            else
            {
                parent->sub_002C1480(request, priority, true);
            }
            break;
        case 1:
            parent->DropCurrent();
            break;
        case 0:
            switch (drive->sub_002AC550())
            {
            case 2:
                if (parent->m_CurrentCancelled)
                {
                    parent->DropCurrent();
                    break;
                }
                parent->sub_002C1760(drive, request);
                // one clear for three ways out: no retry asked for, nothing to tell the game, and after
                // the game has been told
                if (parent->m_Retry)
                {
                    if (parent->m_CurrentCancelled)
                    {
                        if (drive->sub_002AC680() == true)
                        {
                            int saved = drive->sub_002AC3E0();
                            drive->sub_002AC400(0);
                            parent->sub_002C1760(drive, request);
                            drive->sub_002AC400(saved);
                        }
                    }
                    else
                    {
                        parent->sub_002C1480(request, priority, true);
                        parent->m_Retry = false;
                        errorRetry = true;
                        break;
                    }
                }
                parent->sub_002C1850();
                break;
            case 1:
                if (parent->m_CurrentCancelled)
                {
                    parent->sub_002C1850();
                }
                else
                {
                    parent->sub_002C1480(request, priority, true);
                }
                break;
            case 0:
                {
                    // The same six statements once more. The game has them expanded here; written as a
                    // call to DropCurrent the compiler calls the copy instead, so they are written out.
                    parent->Lock();
                    core::Request* current = parent->m_Current;
                    parent->m_CurrentCancelled = false;
                    parent->m_Current = 0;
                    parent->Unlock();
                    delete current;
                }
                break;
            }
            break;
        }
        parent->Lock();
        --parent->m_Outstanding;
        parent->Unlock();
    }
}
