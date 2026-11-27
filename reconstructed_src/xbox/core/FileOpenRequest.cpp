// ============================================================================
// SCARFACE: THE WORLD IS YOURS — Retail Xbox default.xbe, core/FileOpenRequest.cpp (1 verified)
// GENERATED from reports/verified_registry.json by portal/tools/registry_outputs.py. Do not edit.
// PROGRESS: COMPLETE. All 1 functions are matched.
// Every [VERIFIED] block compiled byte-for-byte with Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 13.10.3052 for 80x86.
// Blocks marked 'excerpt' are cut from the named source file and are built from that file;
// every other block compiles on its own. The file as a whole is not one translation unit.
// ============================================================================

// ============================================================================
// [VERIFIED] core::FileOpenRequest::vfunc_01 (0x002A99D0, 561 B)
// By: RRutherrfordd (Founder) | Flags: /O2 /Ot /Oy /G6 /Gd /GR /Zp4
// What it does: Opens a file: first inside the libraries searched before the drive, then on the drive itself, then inside the libraries searched after it.
// ============================================================================
// bin: xb
// va: 0x002A99D0
// what: Opens a file: first inside the libraries searched before the drive, then on the drive itself, then inside the libraries searched after it.
// tool: Claude (from SPEC-020)

unsigned int __cdecl sub_00250E80(unsigned int size, unsigned int unit);

namespace core
{
    class Request;
    class File;
    class Drive;

    // The file's read cache (0x2C bytes, SPEC-020 H4).
    class Cache
    {
    public:
        bool sub_002BE6F0();    // whether it holds the file
        void sub_002BE710();    // closes it
        class File* sub_002BE700();     // the file it holds
        unsigned int sub_001DE0E0();    // its size
        int sub_002BEAC0(Drive* drive, void* handle, const char* name, int base, unsigned int position, void* buffer,
                         unsigned int length, unsigned int* done, int how);     // reads through the cache
        int m_Words[0xB];
    };

    // The media description a drive keeps (0x54 bytes); only its size matters here.
    struct MediaInfo
    {
        unsigned int m_Words[0x15];
    };

    // The real drive (SPEC-016, SPEC-017): the slots its requests call.
    class Drive
    {
    public:
        virtual void vfunc_00();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void vfunc_07();
        virtual unsigned int vfunc_08();
        virtual int vfunc_09();                                             // refresh the media information
        virtual int vfunc_10(const char* name, int mode, bool write, void** handle, unsigned int* size);   // open a file
        virtual int vfunc_11(const char* name, int mode, bool write, void* picture, unsigned int maxSize,
                             void** handle, unsigned int* size);                    // open a saved game
        virtual int vfunc_12(void* handle, const char* name);               // close a file
        virtual int vfunc_13(void* handle, const char* name);               // commit a file
        virtual int vfunc_14(void* handle, const char* name, int base, unsigned int position, void* buffer,
                             unsigned int length, unsigned int* done, int how);             // read
        virtual int vfunc_15(void* handle, const char* name, int base, unsigned int position, const void* buffer,
                             unsigned int length, unsigned int* done, unsigned int* size, int how);  // write
        virtual int vfunc_16();                                             // format
        virtual int vfunc_17(const char* name);                             // create a directory
        virtual int vfunc_18(const char* name);                             // destroy a directory
        virtual int vfunc_19(const char* name);                             // destroy a file
        virtual int vfunc_20(const char* name, int what, void** search, bool first);    // find first
        virtual int vfunc_21(void** search, int what);                      // find next
        virtual void vfunc_22(void** search);                               // find close
        int sub_002AC3E0();                                                 // the drive's last error
        class LibraryList* sub_0017E6E0();                                  // the libraries mounted on it
        MediaInfo* sub_002AC430();                                          // its media information
        void sub_002AC6A0(void* owner, int priority);                       // cancel an owner's requests
        int sub_002AC6E0(int a, int b);                                     // hold a priority (SPEC-018 B.4.4)
        void sub_002AC710(int a, int b);                                    // release it (B.4.6)
        void sub_002AC400(int error);                                       // set the drive's last error
    };

    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    // An open file (SPEC-019 section 3).
    class File : public IRefCount, public IMutable
    {
    public:
        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C
        int m_Priority;         // +0x10
        int m_LastError;        // +0x14
        int m_Outstanding;      // +0x18  requests not finished yet
        bool m_Open;            // +0x1C
        bool m_Write;           // +0x1D
        char m_Name[0x102];     // +0x1E
        int m_Base;             // +0x120
        unsigned int m_Position;    // +0x124
        unsigned int m_Size;        // +0x128
        Cache m_Cache;          // +0x12C
        int m_Field158;         // +0x158
        void* m_Handle;         // +0x15C  the drive's handle for the file
        bool m_SaveGame;        // +0x160
        int m_TransferSize;     // +0x164
    };

    // One user's handle on a drive (SPEC-019 section 2).
    class InstanceDrive : public IRefCount, public IMutable
    {
    public:
        int m_RefCount;         // +0x08
        Drive* m_Drive;         // +0x0C
        int m_Priority;         // +0x10
        int m_Outstanding;      // +0x14
        int m_LastError;        // +0x18
        void* m_Search;         // +0x1C  the drive's handle for the open directory search
        bool m_FindOpen;        // +0x20
    };

    // Work queued on a drive's thread (SPEC-020).
    class Request
    {
    public:
        virtual ~Request();
        virtual int vfunc_01();                 // do the work: 0 error, 1 done, 2 more to do
        virtual bool vfunc_02(void* key);
        virtual Drive* vfunc_03();
        virtual int vfunc_04();                 // prepare again after an error
        virtual int vfunc_05();
        virtual int vfunc_06();
        Request* m_Next;        // +0x04
    };

    // A request on an open file.
    class FileRequest : public Request
    {
    public:
        File* m_File;           // +0x08
        // Records the error on the file under its lock and hands the status back.
        int Finish(int status, int error)
        {
            m_File->Lock();
            m_File->m_LastError = error;
            m_File->Unlock();
            return status;
        }
    };

    // A request on a drive handle.
    class DriveRequest : public Request
    {
    public:
        InstanceDrive* m_Drive; // +0x08
        // Records the error on the drive handle under its lock and hands the status back.
        int Finish(int status, int error)
        {
            m_Drive->Lock();
            m_Drive->m_LastError = error;
            m_Drive->Unlock();
            return status;
        }
    };

    // A library (an archive) mounted on a drive: it can open a file inside itself into a file's read cache.
    class Library
    {
    public:
        bool sub_002AD2C0(const char* name, Cache* cache);
    };

    // A drive's mounted libraries, walked one pass at a time.
    class LibraryList
    {
    public:
        void sub_002ACD30(int pass);        // starts a walk: 0 the libraries searched before the drive, 1 after
        Library* sub_002ACD50();            // the next library, or null
        void sub_002ACD60();                // ends the walk
    };

    class FileOpenRequest : public FileRequest
    {
    public:
        virtual int vfunc_01();
        virtual int vfunc_04();
        int m_Mode;             // +0x0C
        bool m_Write;           // +0x10
    };

}

int core::FileOpenRequest::vfunc_01()
{
    Drive* drive = m_File->m_Drive;
    LibraryList* libraries = drive->sub_0017E6E0();
    Library* library;
    libraries->sub_002ACD30(0);
    while ((library = libraries->sub_002ACD50()) != 0)
    {
        if (library->sub_002AD2C0(m_File->m_Name, &m_File->m_Cache))
        {
            libraries->sub_002ACD60();
            File* inner = m_File->m_Cache.sub_002BE700();
            m_File->m_Handle = inner->m_Handle;
            m_File->m_Size = m_File->m_Cache.sub_001DE0E0();
            m_File->m_Open = true;
            m_File->m_TransferSize = inner->m_TransferSize;
            return Finish(1, 0);
        }
    }
    libraries->sub_002ACD60();
    int status = drive->vfunc_10(m_File->m_Name, m_Mode, m_Write, &m_File->m_Handle, &m_File->m_Size);
    if (status == 1)
    {
        m_File->m_Open = true;
        m_File->m_TransferSize = drive->sub_002AC430()->m_Words[3];
        return Finish(status, drive->sub_002AC3E0());
    }
    libraries->sub_002ACD30(1);
    while ((library = libraries->sub_002ACD50()) != 0)
    {
        if (library->sub_002AD2C0(m_File->m_Name, &m_File->m_Cache))
        {
            libraries->sub_002ACD60();
            File* inner = m_File->m_Cache.sub_002BE700();
            m_File->m_Handle = inner->m_Handle;
            m_File->m_Size = m_File->m_Cache.sub_001DE0E0();
            m_File->m_Open = true;
            m_File->m_TransferSize = inner->m_TransferSize;
            return Finish(1, 0);
        }
    }
    libraries->sub_002ACD60();
    return Finish(status, drive->sub_002AC3E0());
}

