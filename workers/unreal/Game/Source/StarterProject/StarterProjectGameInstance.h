// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "Engine/GameInstance.h"
#include "SpatialOS.h"
#include "StarterProjectGameInstance.generated.h"

class UEntityPipeline;
class UEntityRegistry;
class UCallbackDispatcher;
class USpatialOSComponentUpdater;

/**
 *
 */
UCLASS()
class STARTERPROJECT_API UStarterProjectGameInstance : public UGameInstance
{
    GENERATED_BODY()
  public:
    UStarterProjectGameInstance();
    ~UStarterProjectGameInstance();

    virtual void Init() override;
    virtual void Shutdown() override;

    void ProcessOps(float DeltaTime);

    UFUNCTION(BlueprintCallable, Category = "SpatialOS")
    USpatialOS* GetSpatialOS();

    UFUNCTION(BlueprintCallable, Category = "SpatialOS")
    UEntityRegistry* GetEntityRegistry();

  private:
    UPROPERTY()
    USpatialOS* SpatialOSInstance;

    UPROPERTY()
    UEntityRegistry* EntityRegistry;

    UPROPERTY()
    USpatialOSComponentUpdater* SpatialOSComponentUpdater;

    UFUNCTION()
    void OnSpatialOsConnected();

    UFUNCTION()
    void OnSpatialOsDisconnected();

    FTimerHandle MetricsReporterHandle;
};
