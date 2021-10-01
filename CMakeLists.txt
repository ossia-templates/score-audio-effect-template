cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

if(NOT TARGET score_lib_base)
  include("${SCORE_SOURCE_DIR}/cmake/ScoreExternalAddon.cmake")
endif()

project(score_addon_my_audio_effect LANGUAGES CXX)

add_library(
  score_addon_my_audio_effect
  MyAudioEffect/Distortion.hpp

  score_addon_my_audio_effect.hpp
  score_addon_my_audio_effect.cpp
)

setup_score_plugin(score_addon_my_audio_effect)

target_link_libraries(score_addon_my_audio_effect PUBLIC score_plugin_engine)