
#pragma once

#include <AzCore/Component/Component.h>

#include <PlayFabComboSdk/PlayFabCombo_DataBus.h>

namespace PlayFabComboSdk
{
    class PlayFabCombo_DataSysComponent
        : public AZ::Component
        , protected PlayFabCombo_DataRequestBus::Handler
    {
    public:
        AZ_COMPONENT(PlayFabCombo_DataSysComponent, "{}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        int GetPendingCalls() override;

    protected:
        ////////////////////////////////////////////////////////////////////////
        // PlayFabCombo_DataRequestBus interface implementation

        // ------------ Generated Api calls
        void AbortFileUploads(DataModels::AbortFileUploadsRequest& request, ProcessApiCallback<DataModels::AbortFileUploadsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void DeleteFiles(DataModels::DeleteFilesRequest& request, ProcessApiCallback<DataModels::DeleteFilesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void FinalizeFileUploads(DataModels::FinalizeFileUploadsRequest& request, ProcessApiCallback<DataModels::FinalizeFileUploadsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetFiles(DataModels::GetFilesRequest& request, ProcessApiCallback<DataModels::GetFilesResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void GetObjects(DataModels::GetObjectsRequest& request, ProcessApiCallback<DataModels::GetObjectsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void InitiateFileUploads(DataModels::InitiateFileUploadsRequest& request, ProcessApiCallback<DataModels::InitiateFileUploadsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;
        void SetObjects(DataModels::SetObjectsRequest& request, ProcessApiCallback<DataModels::SetObjectsResponse> callback = nullptr, ErrorCallback errorCallback = nullptr, void* customData = nullptr) override;

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
