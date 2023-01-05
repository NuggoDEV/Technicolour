#include "Hooks.hpp"
#include "ModConfig.hpp"

#include "GlobalNamespace/BeatEffectSpawner.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

Color GradientColour()
{
    
}

MAKE_AUTO_HOOK_MATCH(BeatEffectSpawner_Update, &BeatEffectSpawner::Update, void, BeatEffectSpawner *self)
{
    BeatEffectSpawner_Update(self);

}