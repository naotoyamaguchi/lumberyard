/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
#include "precompiled.h"

#include <ScriptCanvas/Data/DataRegistry.h>

namespace ScriptCanvas
{
    static AZ::EnvironmentVariable<DataRegistry> s_dataRegistry;
    
    static void RegisterSCTypeTraits(DataRegistry& dataRegistry);

    void InitDataRegistry()
    {
        s_dataRegistry = AZ::Environment::CreateVariable<DataRegistry>(s_dataRegistryName);
        RegisterSCTypeTraits(*s_dataRegistry);
    }

    void ResetDataRegistry()
    {
        s_dataRegistry.Reset();
    }

    AZ::EnvironmentVariable<DataRegistry> GetDataRegistry()
    {
        return AZ::Environment::FindVariable<DataRegistry>(s_dataRegistryName);
    }

    void RegisterSCTypeTraits(DataRegistry& dataRegistry)
    {
        auto it = dataRegistry.m_typeIdTraitMap.emplace(Data::eType::Boolean, Data::MakeTypeErasedTraits<Data::eType::Boolean>());
        AZ_Error("Script Canvas", it.second, "Cannot register a second Trait struct with the same ScriptCanvas type(%u)", it.first->first);
        it = dataRegistry.m_typeIdTraitMap.emplace(Data::eType::EntityID, Data::MakeTypeErasedTraits<Data::eType::EntityID>());
        AZ_Error("Script Canvas", it.second, "Cannot register a second Trait struct with the same ScriptCanvas type(%u)", it.first->first);
        it = dataRegistry.m_typeIdTraitMap.emplace(Data::eType::Number, Data::MakeTypeErasedTraits<Data::eType::Number>());
        AZ_Error("Script Canvas", it.second, "Cannot register a second Trait struct with the same ScriptCanvas type(%u)", it.first->first);
        it = dataRegistry.m_typeIdTraitMap.emplace(Data::eType::BehaviorContextObject, Data::MakeTypeErasedTraits<Data::eType::BehaviorContextObject>());
        AZ_Error("Script Canvas", it.second, "Cannot register a second Trait struct with the same ScriptCanvas type(%u)", it.first->first);
        it = dataRegistry.m_typeIdTraitMap.emplace(Data::eType::String, Data::MakeTypeErasedTraits<Data::eType::String>());
        AZ_Error("Script Canvas", it.second, "Cannot register a second Trait struct with the same ScriptCanvas type(%u)", it.first->first);
        it = dataRegistry.m_typeIdTraitMap.emplace(Data::eType::Rotation, Data::MakeTypeErasedTraits<Data::eType::Rotation>());
        AZ_Error("Script Canvas", it.second, "Cannot register a second Trait struct with the same ScriptCanvas type(%u)", it.first->first);
        it = dataRegistry.m_typeIdTraitMap.emplace(Data::eType::Transform, Data::MakeTypeErasedTraits<Data::eType::Transform>());
        AZ_Error("Script Canvas", it.second, "Cannot register a second Trait struct with the same ScriptCanvas type(%u)", it.first->first);
        it = dataRegistry.m_typeIdTraitMap.emplace(Data::eType::Vector2, Data::MakeTypeErasedTraits<Data::eType::Vector2>());
        AZ_Error("Script Canvas", it.second, "Cannot register a second Trait struct with the same ScriptCanvas type(%u)", it.first->first);
        it = dataRegistry.m_typeIdTraitMap.emplace(Data::eType::Vector3, Data::MakeTypeErasedTraits<Data::eType::Vector3>());
        AZ_Error("Script Canvas", it.second, "Cannot register a second Trait struct with the same ScriptCanvas type(%u)", it.first->first);
        it = dataRegistry.m_typeIdTraitMap.emplace(Data::eType::Vector4, Data::MakeTypeErasedTraits<Data::eType::Vector4>());
        AZ_Error("Script Canvas", it.second, "Cannot register a second Trait struct with the same ScriptCanvas type(%u)", it.first->first);
        it = dataRegistry.m_typeIdTraitMap.emplace(Data::eType::AABB, Data::MakeTypeErasedTraits<Data::eType::AABB>());
        AZ_Error("Script Canvas", it.second, "Cannot register a second Trait struct with the same ScriptCanvas type(%u)", it.first->first);
        it = dataRegistry.m_typeIdTraitMap.emplace(Data::eType::Color, Data::MakeTypeErasedTraits<Data::eType::Color>());
        AZ_Error("Script Canvas", it.second, "Cannot register a second Trait struct with the same ScriptCanvas type(%u)", it.first->first);
        it = dataRegistry.m_typeIdTraitMap.emplace(Data::eType::CRC, Data::MakeTypeErasedTraits<Data::eType::CRC>());
        AZ_Error("Script Canvas", it.second, "Cannot register a second Trait struct with the same ScriptCanvas type(%u)", it.first->first);
        it = dataRegistry.m_typeIdTraitMap.emplace(Data::eType::Matrix3x3, Data::MakeTypeErasedTraits<Data::eType::Matrix3x3>());
        AZ_Error("Script Canvas", it.second, "Cannot register a second Trait struct with the same ScriptCanvas type(%u)", it.first->first);
        it = dataRegistry.m_typeIdTraitMap.emplace(Data::eType::Matrix4x4, Data::MakeTypeErasedTraits<Data::eType::Matrix4x4>());
        AZ_Error("Script Canvas", it.second, "Cannot register a second Trait struct with the same ScriptCanvas type(%u)", it.first->first);
        it = dataRegistry.m_typeIdTraitMap.emplace(Data::eType::Plane, Data::MakeTypeErasedTraits<Data::eType::Plane>());
        AZ_Error("Script Canvas", it.second, "Cannot register a second Trait struct with the same ScriptCanvas type(%u)", it.first->first);
        it = dataRegistry.m_typeIdTraitMap.emplace(Data::eType::OBB, Data::MakeTypeErasedTraits<Data::eType::OBB>());
        AZ_Error("Script Canvas", it.second, "Cannot register a second Trait struct with the same ScriptCanvas type(%u)", it.first->first);
    }
}