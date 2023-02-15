#include "main.hpp"
#include "Hooks.hpp"
#include "ModConfig.hpp"

#include "GlobalNamespace/GameplayCoreInstaller.hpp"
#include "GlobalNamespace/AudioTimeSyncController.hpp"
using namespace GlobalNamespace;

#include "sombrero/shared/FastColor.hpp"
using namespace Sombrero;

#include "chroma/shared/SaberAPI.hpp"
#include "chroma/shared/BombAPI.hpp"
#include "chroma/shared/NoteAPI.hpp"
#include "chroma/shared/ObstacleAPI.hpp"
#include "chroma/shared/LightAPI.hpp"

#include <array>
#include <unordered_map>

float leftNote, rightNote, leftSaber, rightSaber;

const int STEPS = 256;
std::vector<FastColor> warmColours, coolColours;

void PrecomputeWarmColours()
{
  warmColours.resize(STEPS + 1);
  for (int i = 0; i < STEPS; i++)
  {
    FastColor colour;

    // Generate warm colors using a mix of red, orange, and yellow
    colour = FastColor::Lerp(FastColor(1.0f, 0.0f, 0.0f), FastColor(1.0f, 0.5f, 0.0f), (float)i / STEPS);
    colour = FastColor::Lerp(colour, FastColor(1.0f, 1.0f, 0.0f), (float)i / STEPS);

    warmColours[i] = colour;
  }
}

FastColor WarmColorGen(int index)
{
  return warmColours[index];
}


void PrecomputeCoolColours()
{
  coolColours.resize(STEPS + 1);
  for (int i = 0; i < STEPS; i++)
  {
    float t = (float)i / STEPS;

    FastColor colour = FastColor::Lerp(FastColor(0.0f, 1.0f, 1.0f), FastColor(0.5f, 0.0f, 1.0f), t);

    coolColours[i] = colour;
  }
}


FastColor WarmGen(int index)
{
  return warmColours[index];
}
FastColor CoolGen(int index)
{
  return coolColours[index];
}



bool LeftNoteWarmToggle, RightNoteCoolToggle, LeftSaberWarmToggle, RightSaberCoolToggle;

MAKE_AUTO_HOOK_MATCH(WC_GameplayCoreInstaller_InstallBindings, &GameplayCoreInstaller::InstallBindings, void, GameplayCoreInstaller *self)
{
  WC_GameplayCoreInstaller_InstallBindings(self);

  if (getModConfig().ForceDisableTechnicolour.GetValue()) return;
  
  PrecomputeWarmColours();
  PrecomputeCoolColours();

  LeftNoteWarmToggle = true;
  RightNoteCoolToggle = true;

  leftNote = getModConfig().LeftNoteWarmCoolOffset.GetValue();
  rightNote = getModConfig().RightNoteWarmCoolOffset.GetValue();
}

MAKE_AUTO_HOOK_MATCH(WC_AudioTimeSyncController_Update, &GlobalNamespace::AudioTimeSyncController::Update, void, GlobalNamespace::AudioTimeSyncController *self)
{
  WC_AudioTimeSyncController_Update(self);

  if (getModConfig().ForceDisableTechnicolour.GetValue()) return;

  if (!getModConfig().ModToggle.GetValue()) return;

  if (getModConfig().NoteStyle.GetValue() == "Warm/Cool")
  {
    FastColor LeftNoteColour = WarmGen(leftNote), RightNoteColour = CoolGen(rightNote);
    Chroma::NoteAPI::setGlobalNoteColorSafe(LeftNoteColour, RightNoteColour);

    Chroma::SaberAPI::setGlobalSaberColorSafe(0, LeftNoteColour);
    Chroma::SaberAPI::setGlobalSaberColorSafe(1, RightNoteColour);
  
    
    // Left Note Int Increase
    if (LeftNoteWarmToggle)
      leftNote++;
    else if (!LeftNoteWarmToggle)
      leftNote--;

    if (leftNote >= 255)
      LeftNoteWarmToggle = false;
    else if (leftNote <= 0)
      LeftNoteWarmToggle = true;

    // Right Note Int Increase
    if (RightNoteCoolToggle)
      rightNote++;
    else if (!RightNoteCoolToggle)
      rightNote--;

    if (rightNote >= 255)
      RightNoteCoolToggle = false;
    else if (rightNote <= 0)
      RightNoteCoolToggle = true;
  }
}