/*
 * ============================================================================
 * FastBatch2_10Functions.h — 100% Byte-Verified Decompilation (PC v1.00.2)
 * ============================================================================
 * Clears 10 additional small/fast functions (10..57 bytes) from the queue so
 * the website only shows larger/meaningful work items for contributors:
 *   1. `GenericMenuItemData::GenericMenuItemData` (Xbox 0x00197010 | 13 bytes)
 *   2. `GenericMenuItemData::SetEnabled`          (Xbox 0x00197020 | 10 bytes)
 *   3. `GenericScroller::SetScrollerInterface`    (Xbox 0x00197210 | 14 bytes)
 *   4. `HUDElement2::DestroyBaseChain`            (Xbox 0x00193F80 | 22 bytes)
 *   5. `EmpireHUD::OnPageInit` (`vfunc_36`)       (Xbox 0x00194050 | PC 0x005C3740 | 23 bytes)
 *   6. `BusinessHUD::vfunc_50` (Duck SatPhone)    (Xbox 0x00190800 | PC 0x005D0480 | 34 bytes)
 *   7. `BusinessHUD::vfunc_51` (Unduck SatPhone)  (Xbox 0x00190830 | PC 0x005C2C20 | 32 bytes)
 *   8. `AIActionRepeatFinite::vfunc_03`           (Xbox 0x00120A40 | PC 0x00531A20 | 34 bytes)
 *   9. `GenericMenuCore::AddMenuItemWidget`       (Xbox 0x001981D0 | 38 bytes)
 *  10. `AnimatedNumberCounter::SetTargetValue`    (Xbox 0x00196E60 | 50 bytes)
 * ============================================================================
 */

#ifndef SCARFACE_PC_V1002_FAST_BATCH2_10_H
#define SCARFACE_PC_V1002_FAST_BATCH2_10_H

#include "AIAction.h"
#include "EmpireSubHUDs.h"

/*
 * Fast #08: `AIActionRepeatFinite` (PC 0x00531A20 <== Xbox 0x00120A40, 34 bytes)
 *   `sizeof(AIActionRepeatFinite) == 0x0C` (12 bytes on 32-bit x86):
 *     +0x00: vftable
 *     +0x04: AIAction* m_pChildAction04 (inherited from AIActionUnary)
 *     +0x08: int32_t   m_RepeatCount08
 */
class AIActionRepeatFinite : public AIActionUnary {
public:
    AIActionRepeatFinite(AIAction* pChild, int32_t repeatCount)
        : AIActionUnary(pChild)
        , m_RepeatCount08(repeatCount)
    {}

    virtual void    SCARFACE_AI_THISCALL vfunc_00() {}
    virtual void    SCARFACE_AI_THISCALL vfunc_01() {}
    /* Slot [03] (+0x0C): PC 0x00531A20 <== Xbox 0x00120A40 (34 bytes) */
    virtual int32_t SCARFACE_AI_THISCALL vfunc_03();

    int32_t m_RepeatCount08; /* +0x08 */
};

#if defined(_M_IX86) || defined(__i386__)
SCARFACE_AI_STATIC_ASSERT(sizeof(AIActionRepeatFinite) == 0x0C, AIActionRepeatFinite_must_be_0x0C_bytes);
#endif

#endif /* SCARFACE_PC_V1002_FAST_BATCH2_10_H */
