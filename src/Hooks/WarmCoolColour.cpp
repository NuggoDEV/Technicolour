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

int i = 10, ii = 160;

const int NUM_STEPS = 256;
std::array<FastColor, NUM_STEPS> WarmColours;
std::array<FastColor, NUM_STEPS> CoolColours;
std::unordered_map<int, FastColor> WarmColourCache;
std::unordered_map<int, FastColor> CoolColourCache;

FastColor getWarmColour(int index)
{
  auto cachedResult = WarmColourCache.find(index);
  if (cachedResult != WarmColourCache.end())
  {
    return cachedResult->second;
  }

  float t = (float)index / NUM_STEPS;
  FastColor colour = FastColor(1.0f, 1.0f - t * 0.5f, 0.0f, t);
  WarmColourCache[index] = colour;
  return colour;
}

FastColor getCoolColour(int index)
{
  auto cachedResult = CoolColourCache.find(index);
  if (cachedResult != CoolColourCache.end())
  {
    return cachedResult->second;
  }

  float t = (float)index / NUM_STEPS;
  FastColor colour = FastColor(0.0f, 1.0f - t, t * 0.5f, 1.0f);
  CoolColourCache[index] = colour;
  return colour;
}

void generateColours()
{
  for (int i = 0; i < NUM_STEPS; i++)
  {
    WarmColours[i] = getWarmColour(i);
    CoolColours[i] = getCoolColour(i);
  }
}


bool WarmToggle = true, CoolToggle = true;

MAKE_AUTO_HOOK_MATCH(WC_GameplayCoreInstaller_InstallBindings, &GameplayCoreInstaller::InstallBindings, void, GameplayCoreInstaller *self)
{
  WC_GameplayCoreInstaller_InstallBindings(self);
  generateColours();
}

MAKE_AUTO_HOOK_MATCH(WC_AudioTimeSyncController_Update, &GlobalNamespace::AudioTimeSyncController::Update, void, GlobalNamespace::AudioTimeSyncController *self)
{
  WC_AudioTimeSyncController_Update(self);

  if (getModConfig().ModToggle.GetValue() && getModConfig().TechniNotes.GetValue() == "Warm/Cold")
  {
    FastColor LeftColour = getWarmColour(i);
    FastColor RightColour = getCoolColour(ii);

    Chroma::NoteAPI::setGlobalNoteColorSafe(LeftColour, RightColour);
    Chroma::SaberAPI::setGlobalSaberColorSafe(SaberType::SaberA, LeftColour);
    Chroma::SaberAPI::setGlobalSaberColorSafe(SaberType::SaberB, RightColour);

    if (WarmToggle)
      i++;
    else if (!WarmToggle)
      i--;

    if (CoolToggle)
      ii++;
    else if (!CoolToggle)
      ii--;

    if (i >= 254)
      WarmToggle = false;
    else if (i <= 10)
      WarmToggle = true;

    if (ii >= 254)
      CoolToggle = false;
    else if (i <= 10)
      CoolToggle = true;
  }
}