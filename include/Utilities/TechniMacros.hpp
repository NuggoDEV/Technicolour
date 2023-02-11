#pragma once

#include "System/IDisposable.hpp"
#include "Zenject/IInitializable.hpp"
#include "custom-types/shared/macros.hpp"
#include "lapiz/shared/macros.hpp"

#define ZENJECT_INTERFACES \
  { classof(::Zenject::IInitializable *), classof(::System::IDisposable *) }

#define DECLARE_CLASS_CODEGEN_ZENJECT(namespaze, klassname, baseT, ...) \
  ___DECLARE_TYPE_WRAPPER_INHERITANCE(                                  \
      namespaze, klassname, Il2CppTypeEnum::IL2CPP_TYPE_CLASS, baseT,   \
      #namespaze, ZENJECT_INTERFACES, 0, nullptr, __VA_ARGS__)

#define DECLARE_OVERRIDE_METHOD_MATCH(retval, name, mptr, ...)      \
  DECLARE_OVERRIDE_METHOD(                                          \
      retval, name,                                                 \
      il2cpp_utils::il2cpp_type_check::MetadataGetter<mptr>::get(), \
      __VA_ARGS__)

#define DECLARE_ZENJECT_INSTALLER(klassName)               \
  DECLARE_CLASS_CODEGEN(                                   \
      Colorama::Installers, klassName, Zenject::Installer, \
      DECLARE_DEFAULT_CTOR();                              \
      DECLARE_OVERRIDE_METHOD_MATCH(void, InstallBindings, \
                                    &Zenject::Installer::InstallBindings);)

template <class T, class U>
bool is_inst(U u) {
  return il2cpp_utils::try_cast<T>(u).has_value();
}