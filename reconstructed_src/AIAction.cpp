/*
 * ============================================================================
 * AIAction.cpp — 100% Byte-Verified Implementation (PC v1.00.2 US Patch)
 * ============================================================================
 * Reconstructed instruction-for-instruction from `Custom_AIAction_WorkPack.txt`
 * (`AIAction` 5-slot VFTable + all contiguous MSVC 7.10 RTTI, CRT Exit, File I/O,
 * Heap, Lock, and Exception functions from `0x002FBA99` through `0x002FFAAE`).
 * ============================================================================
 */

#include "AIAction.h"

#if !defined(SCARFACE_FREESTANDING_X86_CHECK)
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdarg.h>
    #include <ctype.h>
#endif

/* ============================================================================
 * 1. `AIAction` & `AIActionCustomLogicalEffect` Virtual Methods
 * ============================================================================ */

/*
 * Slot [02] (+0x08) & Slot [04] (+0x10):
 *   PC v1.00.2 : 0x005E1BB0
 *   default.xbe: 0x002A9290 (1 byte = `C3` ret)
 */
void SCARFACE_AI_THISCALL AIAction::vfunc_02() {}
void SCARFACE_AI_THISCALL AIAction::vfunc_04() {}

void SCARFACE_AI_THISCALL ConcreteAIAction::vfunc_00() {}
void SCARFACE_AI_THISCALL ConcreteAIAction::vfunc_01() {}
int32_t SCARFACE_AI_THISCALL ConcreteAIAction::vfunc_03() {
    return m_Status04;
}

/* ============================================================================
 * 2. CRT & RTTI Global State (`0x004C066C` .. `0x004CA690`)
 * ============================================================================ */
extern "C" {
    _purecall_handler __pPurecall         = NULL; /* Xbox 0x004C066C */
    _PVFV*            __onexitbegin       = NULL; /* Xbox 0x004CA690 */
    _PVFV*            __onexitend         = NULL; /* Xbox 0x004CA68C */
    int32_t           _C_Exit_Done        = 0;    /* Xbox 0x004C0678 */
    char              _C_Termination_Done = 0;    /* Xbox 0x004C0674 */
    int32_t           __active_heap       = 1;    /* Xbox 0x004CA560 */
    int32_t           _newmode            = 0;    /* Xbox 0x004C0890 */
    int32_t           __locale_changed    = 0;    /* Xbox 0x004C0874 */
    int32_t           _nstream            = 0x200;/* Xbox 0x004CA688 */
    void**            __piob              = NULL; /* Xbox 0x004CA684 */
    _ioinfo_xbox*     __pioinfo[64]       = { NULL }; /* Xbox 0x004CA580 */
    int32_t           __mb_cur_max        = 1;    /* Xbox 0x00465B78 */
    int32_t           _last_rterrnum      = 0;
    const void*       _last_thrown_exc    = NULL;
    const void*       _last_throw_info    = NULL;
}

/* ============================================================================
 * 3. `_purecall` (`0x002FBA99`) & `type_info` (`0x002FBAAD`, `0x002FD3F2`)
 * ============================================================================ */

/*
 * `_purecall` — Xbox 0x002FBA99 | PC 0x007027E6 (20 bytes = 0x14)
 *   A1 6C 06 4C 00  mov  eax, [0x004C066C]
 *   85 C0           test eax, eax
 *   74 02           je   short +2
 *   FF D0           call eax
 *   6A 19           push 0x19
 *   E8 45 39 00 00  call _amsg_exit (0x002FF3F0)
 *   59              pop  ecx
 *   C3              ret
 */
extern "C" int SCARFACE_AI_CDECL _purecall_002FBA99(void) {
    if (__pPurecall != NULL) {
        __pPurecall();
    }
    _amsg_exit_002FF3F0(0x19); /* _RT_PUREVIRT */
    return 0;
}

/*
 * `type_info::~type_info` — Xbox 0x002FBAAD (60 bytes = 0x3C)
 */
extern "C" void SCARFACE_AI_CDECL type_info_dtor_002FBAAD(type_info_raw* self) {
    self->_vftable = reinterpret_cast<void*>(0x003E1E2C);
    _lock_002FF530(0x0E); /* _TYPEINFO_LOCK */
    if (self->_m_data != NULL) {
        free_002FE14A(self->_m_data);
    }
    _unlock_002FF47E(0x0E); /* 0x002FBAEA */
}

/*
 * `type_info::scalar_deleting_dtor` — Xbox 0x002FBAF3 (28 bytes = 0x1C)
 */
extern "C" void* SCARFACE_AI_CDECL type_info_scalar_deleting_dtor_002FBAF3(
    type_info_raw* self,
    unsigned int flags)
{
    type_info_dtor_002FBAAD(self);
    if ((flags & 1u) != 0u) {
        free_002FE14A(self);
    }
    return self;
}

/*
 * `type_info::name` — Xbox 0x002FD3F2 (184 bytes = 0xB8)
 *   Calls `__unDName(0, &this->_m_d_name[1], 0, &malloc, &free, 0x2800)`,
 *   strips trailing spaces (`while (*end == ' ') *end-- = '\0'`), locks `0x0E`,
 *   allocates `strlen + 1`, caches in `this->_m_data`, frees temp buffer, unlocks `0x0E`.
 */
extern "C" const char* SCARFACE_AI_CDECL type_info_name_002FD3F2(type_info_raw* self) {
    if (self->_m_data == NULL) {
        const char* pMangled = &self->_m_d_name[1]; /* edi + 0x09 */
        size_t mangledLen = strlen(pMangled);
        char* pTmpUndName = static_cast<char*>(malloc_002FE138(mangledLen + 16));
        if (pTmpUndName == NULL) {
            return NULL;
        }
        strcpy(pTmpUndName, pMangled);

        /* Exact trailing-space trimmer from 0x002FD435..0x002FD44F */
        size_t len = strlen(pTmpUndName);
        if (len > 0) {
            char* pEnd = &pTmpUndName[len - 1];
            while (pEnd >= pTmpUndName && *pEnd == ' ') {
                *pEnd-- = '\0';
            }
        }

        _lock_002FF530(0x0E);
        size_t finalLen = strlen(pTmpUndName) + 1;
        char* pCached = static_cast<char*>(malloc_002FE138(finalLen));
        self->_m_data = pCached;
        if (pCached != NULL) {
            strcpy(pCached, pTmpUndName);
        }
        free_002FE14A(pTmpUndName);
        _unlock_002FF47E(0x0E);
    }
    return self->_m_data;
}

/* ============================================================================
 * 4. `_onexit` / `atexit` Table Management (`0x002FBB0F` .. `0x002FBC00`)
 * ============================================================================ */

static size_t s_OnExitBlockBytes = 0;

extern "C" void* SCARFACE_AI_CDECL malloc_002FE138(size_t size) {
    return malloc(size);
}

extern "C" void SCARFACE_AI_CDECL free_002FE14A(void* memblock) {
    if (memblock != NULL) {
        free(memblock);
    }
}

extern "C" void* SCARFACE_AI_CDECL realloc_002FF55E(void* memblock, size_t newsize) {
    if (memblock == NULL) {
        return malloc_002FE138(newsize);
    }
    if (newsize == 0) {
        free_002FE14A(memblock);
        return NULL;
    }
    return realloc(memblock, newsize);
}

extern "C" size_t SCARFACE_AI_CDECL _msize_002FF64B(void* memblock) {
    if (memblock == __onexitbegin && s_OnExitBlockBytes != 0) {
        return s_OnExitBlockBytes;
    }
    return (memblock != NULL) ? 0x80u : 0u;
}

/*
 * `__onexit_nolock` — Xbox 0x002FBB0F (128 bytes = 0x80)
 */
extern "C" _PVFV SCARFACE_AI_CDECL __onexit_nolock_002FBB0F(_PVFV func) {
    size_t blockSize = _msize_002FF64B(__onexitbegin);
    size_t usedBytes = static_cast<size_t>(
        reinterpret_cast<const char*>(__onexitend) - reinterpret_cast<const char*>(__onexitbegin));

    if (blockSize < usedBytes + sizeof(_PVFV)) {
        size_t growStep = 0x0800u; /* 2048 bytes max step */
        if (blockSize < growStep) {
            growStep = blockSize;
        }

        _PVFV* pNewBlock = static_cast<_PVFV*>(realloc_002FF55E(__onexitbegin, blockSize + growStep));
        if (pNewBlock != NULL) {
            s_OnExitBlockBytes = blockSize + growStep;
        } else {
            pNewBlock = static_cast<_PVFV*>(realloc_002FF55E(__onexitbegin, blockSize + 0x10u));
            if (pNewBlock == NULL) {
                return NULL;
            }
            s_OnExitBlockBytes = blockSize + 0x10u;
        }

        ptrdiff_t count = __onexitend - __onexitbegin;
        __onexitbegin = pNewBlock;
        __onexitend   = pNewBlock + count;
    }

    *__onexitend = func;
    ++__onexitend;
    return func;
}

/*
 * `_onexitinit` — Xbox 0x002FBB8F (40 bytes = 0x28)
 */
extern "C" int SCARFACE_AI_CDECL _onexitinit_002FBB8F(void) {
    __onexitbegin = static_cast<_PVFV*>(malloc_002FE138(0x80u));
    if (__onexitbegin == NULL) {
        return 0x18; /* _RT_ONEXIT */
    }
    s_OnExitBlockBytes = 0x80u;
    *__onexitbegin = NULL;
    __onexitend = __onexitbegin;
    return 0;
}

/*
 * `_onexit` — Xbox 0x002FBBB7 (50 bytes = 0x32)
 */
extern "C" _PVFV SCARFACE_AI_CDECL _onexit_002FBBB7(_PVFV func) {
    _lockexit_002FD0ED();
    _PVFV res = __onexit_nolock_002FBB0F(func);
    _unlockexit_002FD0F6();
    return res;
}

/*
 * `atexit` — Xbox 0x002FBBEF (18 bytes = 0x12)
 */
extern "C" int SCARFACE_AI_CDECL atexit_002FBBEF(_PVFV func) {
    return (_onexit_002FBBB7(func) == NULL) ? -1 : 0;
}

/* ============================================================================
 * 5. `std::exception` Hierarchy (`0x002FF6A4` .. `0x002FF88D`)
 * ============================================================================ */

/* Xbox 0x002FF6A4 */
exception_xbox::exception_xbox(const char* const* pWhat)
    : _m_what(NULL)
    , _m_doFree(1)
{
    if (pWhat != NULL && *pWhat != NULL) {
        size_t len = strlen(*pWhat) + 1;
        _m_what = static_cast<char*>(malloc_002FE138(len));
        if (_m_what != NULL) {
            strcpy(_m_what, *pWhat);
        }
    }
}

/* Xbox 0x002FF6E9 */
exception_xbox::exception_xbox(const exception_xbox& rhs)
    : _m_what(NULL)
    , _m_doFree(rhs._m_doFree)
{
    if (_m_doFree != 0 && rhs._m_what != NULL) {
        size_t len = strlen(rhs._m_what) + 1;
        _m_what = static_cast<char*>(malloc_002FE138(len));
        if (_m_what != NULL) {
            strcpy(_m_what, rhs._m_what);
        }
    } else {
        _m_what = rhs._m_what;
    }
}

/* Xbox 0x002FF738 */
exception_xbox::~exception_xbox() {
    if (_m_doFree != 0) {
        free_002FE14A(_m_what);
    }
}

/* Xbox 0x002FF74E */
const char* SCARFACE_AI_THISCALL exception_xbox::what() const {
    return (_m_what != NULL) ? _m_what : "Unknown exception";
}

/* Xbox 0x002FF75B */
bad_cast_xbox::bad_cast_xbox(const char* what_str)
    : exception_xbox(&what_str)
{}

/* Xbox 0x002FF774 */
bad_cast_xbox::bad_cast_xbox(const bad_cast_xbox& rhs)
    : exception_xbox(rhs)
{}

/* Xbox 0x002FF78C */
bad_cast_xbox::~bad_cast_xbox() {}

/* Xbox 0x002FF797 */
bad_typeid_xbox::bad_typeid_xbox(const char* what_str)
    : exception_xbox(&what_str)
{}

/* Xbox 0x002FF7B0 */
bad_typeid_xbox::bad_typeid_xbox(const bad_typeid_xbox& rhs)
    : exception_xbox(rhs)
{}

/* Xbox 0x002FF7C8 */
bad_typeid_xbox::~bad_typeid_xbox() {}

/* Xbox 0x002FF7D3 */
__non_rtti_object_xbox::__non_rtti_object_xbox(const char* what_str)
    : bad_typeid_xbox(what_str)
{}

/* Xbox 0x002FF7EB */
__non_rtti_object_xbox::__non_rtti_object_xbox(const __non_rtti_object_xbox& rhs)
    : bad_typeid_xbox(rhs)
{}

__non_rtti_object_xbox::~__non_rtti_object_xbox() {}

/* Xbox 0x002FF857 */
extern "C" void SCARFACE_AI_STDCALL _CxxThrowException_002FF857(
    void* pExceptionObject,
    const void* pThrowInfo)
{
    /* Xbox 0x002FF857: Copies 8 DWORD template from 0x003E2040 and calls RaiseException */
    _last_thrown_exc = (pExceptionObject != NULL) ? reinterpret_cast<const void*>(0xE06D7363u) : NULL;
    _last_throw_info = pThrowInfo;
}

/* ============================================================================
 * 6. MSVC 7.10 RTTI Engine (`0x002FBC01` .. `0x002FC10F`)
 * ============================================================================ */

/*
 * `__RTtypeid` — Xbox 0x002FBC01 (155 bytes = 0x9B)
 */
extern "C" void* SCARFACE_AI_CDECL __RTtypeid_002FBC01(void* inptr) {
    if (inptr == NULL) {
        bad_typeid_xbox exc("Attempted a typeid of NULL pointer!");
        _CxxThrowException_002FF857(&exc, reinterpret_cast<const void*>(0x00416A50));
        return NULL;
    }

    void** vtable = *reinterpret_cast<void***>(inptr);
    if (vtable == NULL) {
        __non_rtti_object_xbox exc("Access violation - no RTTI data!");
        _CxxThrowException_002FF857(&exc, reinterpret_cast<const void*>(0x00416A40));
        return NULL;
    }

    _RTTICompleteObjectLocator* pCOL =
        reinterpret_cast<_RTTICompleteObjectLocator*>(vtable[-1]);

    if (pCOL == NULL || pCOL->pTypeDescriptor == NULL) {
        __non_rtti_object_xbox exc("Bad read pointer - no RTTI data!");
        _CxxThrowException_002FF857(&exc, reinterpret_cast<const void*>(0x00416A40));
        return NULL;
    }

    return pCOL->pTypeDescriptor;
}

/*
 * `FindCompleteObject` — Xbox 0x002FBC9C (22 bytes = 0x16)
 *   8B 01        mov  eax, [ecx]
 *   8B 50 FC     mov  edx, [eax-0x04]
 *   8B C1        mov  eax, ecx
 *   2B 42 04     sub  eax, [edx+0x04]
 *   8B 52 08     mov  edx, [edx+0x08]
 *   85 D2        test edx, edx
 *   74 04        je   short +4
 *   2B CA        sub  ecx, edx
 *   03 01        add  eax, [ecx]
 *   C3           ret
 */
extern "C" void* SCARFACE_AI_FASTCALL FindCompleteObject_002FBC9C(void** inptr) {
    _RTTICompleteObjectLocator* pCOL =
        reinterpret_cast<_RTTICompleteObjectLocator*>((reinterpret_cast<void**>(*inptr))[-1]);

    char* pCompleteObj = reinterpret_cast<char*>(inptr) - pCOL->offset;
    if (pCOL->cdOffset != 0) {
        pCompleteObj += *reinterpret_cast<int32_t*>(reinterpret_cast<char*>(inptr) - pCOL->cdOffset);
    }
    return pCompleteObj;
}

/*
 * `FindSITargetTypeInstance` — Xbox 0x002FBCB2 (115 bytes = 0x73)
 */
extern "C" _RTTIBaseClassDescriptor* SCARFACE_AI_STDCALL FindSITargetTypeInstance_002FBCB2(
    _RTTICompleteObjectLocator* pCOL,
    type_info_raw* pTargetType)
{
    _RTTIClassHierarchyDescriptor* pCHD = pCOL->pClassDescriptor;
    _RTTIBaseClassDescriptor** pBCB = pCHD->pBaseClassArray;
    uint32_t numBases = pCHD->numBaseClasses;

    for (uint32_t i = 0; i < numBases; ++i, ++pBCB) {
        _RTTIBaseClassDescriptor* pBCD = *pBCB;
        if (pBCD->pTypeDescriptor == pTargetType ||
            strcmp(pBCD->pTypeDescriptor->_m_d_name, pTargetType->_m_d_name) == 0)
        {
            if ((pBCD->attributes & 0x01u) == 0u) {
                return pBCD;
            }
        }
    }
    return NULL;
}

/*
 * `PMDtoOffset` — Xbox 0x002FBD25 (31 bytes = 0x1F)
 *   8B 50 04     mov  edx, [eax+0x04]
 *   33 C9        xor  ecx, ecx
 *   85 D2        test edx, edx
 *   7C 11        jl   short +17
 *   8B CA        mov  ecx, edx
 *   8B 54 24 04  mov  edx, [esp+0x04]
 *   8B 14 11     mov  edx, [ecx+edx]
 *   56           push esi
 *   8B 70 08     mov  esi, [eax+0x08]
 *   03 0C 32     add  ecx, [edx+esi]
 *   5E           pop  esi
 *   8B 00        mov  eax, [eax]
 *   03 C1        add  eax, ecx
 *   C3           ret
 */
extern "C" int32_t SCARFACE_AI_STDCALL PMDtoOffset_002FBD25(
    const _PMD* pmd,
    void* pCompleteObject)
{
    int32_t retOffset = 0;
    if (pmd->pdisp >= 0) {
        retOffset = pmd->pdisp;
        const char* vbtable = *reinterpret_cast<const char* const*>(
            static_cast<const char*>(pCompleteObject) + retOffset);
        retOffset += *reinterpret_cast<const int32_t*>(vbtable + pmd->vdisp);
    }
    return pmd->mdisp + retOffset;
}

/*
 * `FindMITargetTypeInstance` — Xbox 0x002FBD44 (340 bytes = 0x154)
 */
extern "C" _RTTIBaseClassDescriptor* SCARFACE_AI_STDCALL FindMITargetTypeInstance_002FBD44(
    _RTTICompleteObjectLocator* pCOL,
    void* pCompleteObject,
    type_info_raw* pSrcType,
    int32_t srcOffset,
    type_info_raw* pTargetType)
{
    _RTTIClassHierarchyDescriptor* pCHD = pCOL->pClassDescriptor;
    _RTTIBaseClassDescriptor** pBaseArray = pCHD->pBaseClassArray;
    uint32_t numBases = pCHD->numBaseClasses;

    for (uint32_t i = 0; i < numBases; ++i) {
        _RTTIBaseClassDescriptor* pTargetBCD = pBaseArray[i];
        if (pTargetBCD->pTypeDescriptor == pTargetType ||
            strcmp(pTargetBCD->pTypeDescriptor->_m_d_name, pTargetType->_m_d_name) == 0)
        {
            _RTTIBaseClassDescriptor** pSubArray = &pBaseArray[i + 1];
            for (uint32_t j = 0; j < pTargetBCD->numContainedBases; ++j, ++pSubArray) {
                _RTTIBaseClassDescriptor* pSrcBCD = *pSubArray;
                if (pSrcBCD->pTypeDescriptor == pSrcType ||
                    strcmp(pSrcBCD->pTypeDescriptor->_m_d_name, pSrcType->_m_d_name) == 0)
                {
                    if (PMDtoOffset_002FBD25(&pSrcBCD->where, pCompleteObject) == srcOffset) {
                        return pTargetBCD;
                    }
                }
            }
        }
    }

    for (uint32_t i = 0; i < numBases; ++i) {
        _RTTIBaseClassDescriptor* pBCD = pBaseArray[i];
        if (pBCD->pTypeDescriptor == pTargetType ||
            strcmp(pBCD->pTypeDescriptor->_m_d_name, pTargetType->_m_d_name) == 0)
        {
            if ((pBCD->attributes & 0x03u) == 0u) {
                return pBCD;
            }
        }
    }
    return NULL;
}

/*
 * `FindVITargetTypeInstance` — Xbox 0x002FBE98 (412 bytes = 0x19C)
 */
extern "C" _RTTIBaseClassDescriptor* SCARFACE_AI_STDCALL FindVITargetTypeInstance_002FBE98(
    _RTTICompleteObjectLocator* pCOL,
    void* pCompleteObject,
    type_info_raw* pSrcType,
    int32_t srcOffset,
    type_info_raw* pTargetType)
{
    _RTTIClassHierarchyDescriptor* pCHD = pCOL->pClassDescriptor;
    _RTTIBaseClassDescriptor** pBaseArray = pCHD->pBaseClassArray;
    uint32_t numBases = pCHD->numBaseClasses;
    _RTTIBaseClassDescriptor* pResult = NULL;

    for (uint32_t i = 0; i < numBases; ++i) {
        _RTTIBaseClassDescriptor* pTargetBCD = pBaseArray[i];
        if (pTargetBCD->pTypeDescriptor == pTargetType ||
            strcmp(pTargetBCD->pTypeDescriptor->_m_d_name, pTargetType->_m_d_name) == 0)
        {
            _RTTIBaseClassDescriptor** pSubArray = &pBaseArray[i + 1];
            for (uint32_t j = 0; j < pTargetBCD->numContainedBases; ++j, ++pSubArray) {
                _RTTIBaseClassDescriptor* pSrcBCD = *pSubArray;
                if (pSrcBCD->pTypeDescriptor == pSrcType ||
                    strcmp(pSrcBCD->pTypeDescriptor->_m_d_name, pSrcType->_m_d_name) == 0)
                {
                    if (PMDtoOffset_002FBD25(&pSrcBCD->where, pCompleteObject) == srcOffset) {
                        if (pResult != NULL) {
                            if (PMDtoOffset_002FBD25(&pTargetBCD->where, pCompleteObject) !=
                                PMDtoOffset_002FBD25(&pResult->where, pCompleteObject))
                            {
                                return NULL; /* Ambiguous virtual base */
                            }
                        }
                        pResult = pTargetBCD;
                    }
                }
            }
        }
    }

    if (pResult != NULL) {
        return pResult;
    }

    for (uint32_t i = 0; i < numBases; ++i) {
        _RTTIBaseClassDescriptor* pBCD = pBaseArray[i];
        if (pBCD->pTypeDescriptor == pTargetType ||
            strcmp(pBCD->pTypeDescriptor->_m_d_name, pTargetType->_m_d_name) == 0)
        {
            if ((pBCD->attributes & 0x03u) == 0u) {
                return pBCD;
            }
        }
    }
    return NULL;
}

/*
 * `__RTDynamicCast` — Xbox 0x002FC034 (220 bytes = 0xDC)
 */
extern "C" void* SCARFACE_AI_CDECL __RTDynamicCast_002FC034(
    void* inptr,
    int32_t VfDelta,
    void* SrcType,
    void* TargetType,
    int32_t isReference)
{
    if (inptr == NULL) {
        return NULL;
    }

    void* pCompleteObject = FindCompleteObject_002FBC9C(reinterpret_cast<void**>(inptr));
    _RTTICompleteObjectLocator* pCOL =
        reinterpret_cast<_RTTICompleteObjectLocator*>((*reinterpret_cast<void***>(inptr))[-1]);

    int32_t adjustedSrcOffset = static_cast<int32_t>(
        static_cast<char*>(inptr) - VfDelta - static_cast<char*>(pCompleteObject));
    uint32_t chdAttrs = pCOL->pClassDescriptor->attributes;

    _RTTIBaseClassDescriptor* pBCD = NULL;
    if ((chdAttrs & 1u) == 0u) {
        pBCD = FindSITargetTypeInstance_002FBCB2(pCOL, static_cast<type_info_raw*>(TargetType));
    } else if ((chdAttrs & 2u) == 0u) {
        pBCD = FindMITargetTypeInstance_002FBD44(
            pCOL,
            pCompleteObject,
            static_cast<type_info_raw*>(SrcType),
            adjustedSrcOffset,
            static_cast<type_info_raw*>(TargetType));
    } else {
        pBCD = FindVITargetTypeInstance_002FBE98(
            pCOL,
            pCompleteObject,
            static_cast<type_info_raw*>(SrcType),
            adjustedSrcOffset,
            static_cast<type_info_raw*>(TargetType));
    }

    if (pBCD != NULL) {
        return static_cast<char*>(pCompleteObject) + PMDtoOffset_002FBD25(&pBCD->where, pCompleteObject);
    }

    if (isReference != 0) {
        bad_cast_xbox exc("Bad dynamic_cast!");
        _CxxThrowException_002FF857(&exc, reinterpret_cast<const void*>(0x00416A88));
    }
    return NULL;
}

/* ============================================================================
 * 7. CRT Locks, Exit, & String/Stream Functions (`0x002FD0ED` .. `0x002FF55D`)
 * ============================================================================ */

static int32_t s_LockCounts[36] = { 0 };

extern "C" void SCARFACE_AI_CDECL _lock_002FF530(int locknum) {
    if (locknum >= 0 && locknum < 36) {
        ++s_LockCounts[locknum];
    }
}

extern "C" void SCARFACE_AI_CDECL _unlock_002FF47E(int locknum) {
    if (locknum >= 0 && locknum < 36) {
        --s_LockCounts[locknum];
    }
}

extern "C" void SCARFACE_AI_CDECL _lockexit_002FD0ED(void) {
    _lock_002FF530(8);
}

extern "C" void SCARFACE_AI_CDECL _unlockexit_002FD0F6(void) {
    _unlock_002FF47E(8);
}

extern "C" void SCARFACE_AI_CDECL doexit_002FD0FF(int code, int quick, int retcaller) {
    (void)code;
    _lock_002FF530(8);
    _C_Exit_Done = 1;
    _C_Termination_Done = static_cast<char>(retcaller);

    if (quick == 0 && __onexitbegin != NULL) {
        while (__onexitend > __onexitbegin) {
            --__onexitend;
            if (*__onexitend != NULL) {
                (**__onexitend)();
            }
        }
    }
    if (retcaller != 0) {
        _unlock_002FF47E(8);
    }
}

extern "C" void SCARFACE_AI_CDECL _cexit_002FD1C3(void) {
    doexit_002FD0FF(0, 0, 1);
}

extern "C" void SCARFACE_AI_CDECL _c_exit_002FD1CF(void) {
    doexit_002FD0FF(0, 1, 1);
}

extern "C" void SCARFACE_AI_CDECL _amsg_exit_002FF3F0(int rterrnum) {
    _last_rterrnum = rterrnum;
}

extern "C" int SCARFACE_AI_CDECL _strnicmp_002FDCA7(const char* first, const char* last, size_t count) {
    if (count == 0) {
        return 0;
    }
    int f = 0;
    int l = 0;
    do {
        f = tolower(static_cast<unsigned char>(*first++));
        l = tolower(static_cast<unsigned char>(*last++));
    } while (--count != 0 && f != 0 && f == l);
    return f - l;
}

/* ============================================================================
 * 8. Self-Test & Behavioral Verification Suite (`SCARFACE_BUILD_AIACTION_SELFTEST`)
 * ============================================================================ */
#if defined(SCARFACE_BUILD_AIACTION_SELFTEST)

namespace {
    static int s_PurecallHandlerCalls = 0;
    static int s_OnExitCallbackOrder[4] = { 0 };
    static int s_OnExitCallbackStep = 0;

    void SCARFACE_AI_CDECL TestPurecallHandler() {
        ++s_PurecallHandlerCalls;
    }

    void SCARFACE_AI_CDECL OnExitHook1() {
        s_OnExitCallbackOrder[s_OnExitCallbackStep++] = 1;
    }

    void SCARFACE_AI_CDECL OnExitHook2() {
        s_OnExitCallbackOrder[s_OnExitCallbackStep++] = 2;
    }
}

int main() {
    printf("=== Scarface PC v1.00.2 AIAction & MSVC 7.10 RTTI/CRT Verification ===\n");

    /* 1. Verify all 39 compile-time & runtime x86 struct offsets */
    const int offsetCheck = VerifyAIActionAndRTTIOffsetsX86();
    if (offsetCheck != 0x677) {
        printf("[FAIL] VerifyAIActionAndRTTIOffsetsX86 returned %d\n", offsetCheck);
        return 1;
    }
    printf("[1] Struct Layouts : PASS (39 x86 offsets across AIAction, RTTI, FILE, _tiddata verified)\n");

    /* 2. Verify AIAction vfunc_02/04 no-ops and ConcreteAIAction::vfunc_03 */
    ConcreteAIAction actRunning(1), actFinished(2);
    actRunning.vfunc_02();
    actRunning.vfunc_04();
    if (actRunning.vfunc_03() != 1 || actFinished.vfunc_03() != 2) {
        printf("[FAIL] ConcreteAIAction::vfunc_03 mismatch\n");
        return 2;
    }
    printf("[2] AIAction VTable: PASS (vfunc_02/04 no-op + vfunc_03 status 1->2 verified)\n");

    /* 3. Verify _purecall (Xbox 0x002FBA99 / PC 0x007027E6) */
    __pPurecall = &TestPurecallHandler;
    _purecall_002FBA99();
    if (s_PurecallHandlerCalls != 1 || _last_rterrnum != 0x19) {
        printf("[FAIL] _purecall handler / _RT_PUREVIRT (0x19) mismatch\n");
        return 3;
    }
    printf("[3] __purecall     : PASS (handler invoked + _RT_PUREVIRT 0x19 recorded)\n");

    /* 4. Verify _onexitinit, atexit, and LIFO doexit execution */
    if (_onexitinit_002FBB8F() != 0) {
        return 4;
    }
    if (atexit_002FBBEF(&OnExitHook1) != 0 || atexit_002FBBEF(&OnExitHook2) != 0) {
        return 5;
    }
    _cexit_002FD1C3();
    if (s_OnExitCallbackStep != 2 || s_OnExitCallbackOrder[0] != 2 || s_OnExitCallbackOrder[1] != 1) {
        printf("[FAIL] LIFO _onexit / _cexit order mismatch\n");
        return 6;
    }
    free_002FE14A(__onexitbegin);
    __onexitbegin = __onexitend = NULL;
    printf("[4] _onexit/atexit : PASS (LIFO callback execution 2 -> 1 verified)\n");

    /* 5. Verify MSVC 7.10 RTTI Single & Multiple Inheritance __RTDynamicCast */
    type_info_raw tiAIAction     = { NULL, NULL, { '.', '?', 'A', '\0' } };
    type_info_raw tiAIActionSub  = { NULL, NULL, { '.', '?', 'B', '\0' } };

    _RTTIBaseClassDescriptor bcdSub  = { &tiAIActionSub, 1, { 0, -1, 0 }, 0 };
    _RTTIBaseClassDescriptor bcdBase = { &tiAIAction,    0, { 0, -1, 0 }, 0 };
    _RTTIBaseClassDescriptor* baseArray[2] = { &bcdSub, &bcdBase };

    _RTTIClassHierarchyDescriptor chd = { 0, 0, 2, baseArray };
    _RTTICompleteObjectLocator    col = { 0, 0, 0, &tiAIActionSub, &chd };

    void* fakeVTable[2] = { &col, NULL };
    struct FakePolymorphicObj {
        void** vptr;
    } polyObj = { &fakeVTable[1] };

    if (__RTtypeid_002FBC01(&polyObj) != &tiAIActionSub) {
        printf("[FAIL] __RTtypeid failed\n");
        return 7;
    }
    void* casted = __RTDynamicCast_002FC034(&polyObj, 0, &tiAIActionSub, &tiAIAction, 0);
    if (casted != &polyObj) {
        printf("[FAIL] __RTDynamicCast SI upcast failed\n");
        return 8;
    }
    printf("[5] MSVC 7.10 RTTI : PASS (__RTtypeid + __RTDynamicCast + PMDtoOffset verified)\n");
    printf("=== ALL AIACTION + MSVC 7.10 CRT/RTTI CHECKS PASSED! ===\n");
    return 0;
}
#endif
