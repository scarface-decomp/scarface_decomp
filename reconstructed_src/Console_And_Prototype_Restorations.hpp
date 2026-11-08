/*
 * Console_And_Prototype_Restorations.hpp
 * Master Feature Toggles for Non-PC Content (Xbox Retail, April 2006 Prototype, PS2, Wii)
 * Leave all #defines commented out for strict 1:1 Vanilla PC v1.00.2 (`Scarface.exe`) builds.
 */
#pragma once

// 1. April 20, 2006 Xbox Prototype (`binaries/game.xbe`) — 184 Cut Classes
// Restores: AIActionRepeatFinite, Mod_Kamikaze, Cmd_Skull, BoatAITask_Traffic, BusinessDetailHUD::DetailMenuItem
#define SCARFACE_RESTORE_PROTO_CUT_CONTENT 1

// 2. Retail Xbox Console Exclusives (`binaries/default.xbe`) — 34 Classes
// Restores: pure3d::d3dExtGlobalProjectedTexture, audio::ListenerEffectXBox, core::ControllerXBox
#define SCARFACE_RESTORE_XBOX_EXCLUSIVES 1

// 3. PlayStation 2 & Nintendo Wii Exclusives — 32+ Platform Classes
// Restores: PS2 lighting/bloom passes, Wii pointer/motion weapon aiming hooks
#define SCARFACE_RESTORE_PS2_WII_FEATURES 1
