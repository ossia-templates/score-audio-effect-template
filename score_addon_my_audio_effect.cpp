#include "score_addon_my_audio_effect.hpp"

#include <score/plugins/FactorySetup.hpp>

#include <MyAudioEffect/Distortion.hpp>
#include <score_plugin_engine.hpp>

/**
 * This file instantiates the classes that are provided by this plug-in.
 */

score_addon_my_audio_effect::score_addon_my_audio_effect() = default;
score_addon_my_audio_effect::~score_addon_my_audio_effect() = default;

std::vector<std::unique_ptr<score::InterfaceBase>>
score_addon_my_audio_effect::factories(
    const score::ApplicationContext& ctx,
    const score::InterfaceKey& key) const
{
  return Control::instantiate_fx<MyAudioEffect::Distortion>(ctx, key);
}

std::vector<score::PluginKey> score_addon_my_audio_effect::required() const
{
  return {score_plugin_engine::static_key()};
}

#include <score/plugins/PluginInstances.hpp>
SCORE_EXPORT_PLUGIN(score_addon_my_audio_effect)
