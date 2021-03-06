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

#pragma once

#ifdef AZ_PROFILE_TELEMETRY

#include <AzCore/std/parallel/threadbus.h>
#include <AzCore/Component/Component.h>
#include <AzCore/Component/TickBus.h>
#include <AzCore/std/string/string.h>

#include <RADTelemetry/ProfileTelemetryBus.h>

namespace RADTelemetry
{
    class ProfileTelemetryComponent
        : public AZ::Component
        , private AZStd::ThreadEventBus::Handler
        , private AZ::SystemTickBus::Handler
        , private ProfileTelemetryRequestBus::Handler
    {
    public:
        AZ_COMPONENT(ProfileTelemetryComponent, "{51118122-7214-4918-BFF3-237E25FF4918}");

        ProfileTelemetryComponent();
        ~ProfileTelemetryComponent() override;

        //////////////////////////////////////////////////////////////////////////
        // AZ::Component
        void Activate() override;
        void Deactivate() override;

    private:
        ProfileTelemetryComponent(const ProfileTelemetryComponent&) = delete;
        //////////////////////////////////////////////////////////////////////////
        // Thread event bus
        void OnThreadEnter(const AZStd::thread_id& id, const AZStd::thread_desc* desc) override;
        void OnThreadExit(const AZStd::thread_id& id) override;

        //////////////////////////////////////////////////////////////////////////
        // SystemTick event bus
        void OnSystemTick() override;

        //////////////////////////////////////////////////////////////////////////
        // ProfileTelemetryRequestBus
        void ToggleEnabled() override;
        void SetAddress(const char *address, AZ::u16 port) override;
        void SetCaptureMask(AZ::u32 mask) override;
        tm_api* GetApiInstance() override;

        //////////////////////////////////////////////////////////////////////////
        // Component descriptor
        static void Reflect(AZ::ReflectContext* context);
        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);

        //////////////////////////////////////////////////////////////////////////
        // Private helpers
        void Enable();
        void Disable();
        void Initialize();
        bool IsInitialized() const;

        //////////////////////////////////////////////////////////////////////////
        // Data members
        struct ThreadNameEntry
        {
            AZStd::thread_id id;
            AZStd::string name;
        };
        AZStd::vector<ThreadNameEntry> m_threadNames;
        using LockType = AZStd::mutex;
        using ScopedLock = AZStd::lock_guard<LockType>;
        LockType m_threadNameLock;
        AZStd::atomic_uint m_profiledThreadCount = 0;

        const char* m_address = "127.0.0.1";
        char* m_buffer = nullptr;
        AZ::u32 m_captureMask = 0;
        AZ::u16 m_port = 4719;
        bool m_running = false;
        bool m_initialized = false;
    };
}

#endif
