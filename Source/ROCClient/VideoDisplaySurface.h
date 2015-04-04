// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "IVideoSource.h"
#include "VideoDisplaySurface.generated.h"

UCLASS()
class ROCCLIENT_API AVideoDisplaySurface : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AVideoDisplaySurface(const class FObjectInitializer& PCIP);

	// mesh to use
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = AugmentedReality)
		TSubobjectPtr<UStaticMeshComponent> VideoSurfaceMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AugmentedReality)
		float PreferredDistanceInMeters;

	UFUNCTION(BlueprintCallable, Category = AugmentedReality)
		uint16 GetWidthToDistanceRatio();

	UFUNCTION(BlueprintCallable, Category = AugmentedReality)
		uint16 GetHeightToDistanceRatio();

	void Init(IVideoSource* VideoSource);

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = AugmentedReality)
		UTexture2D* VideoTexture;

	/** Update texture region from https://wiki.unrealengine.com/Dynamic_Textures */
	void UpdateTextureRegions(UTexture2D* Texture, int32 MipIndex, uint32 NumRegions, FUpdateTextureRegion2D* Regions, uint32 SrcPitch, uint32 SrcBpp, uint8* SrcData, bool bFreeData);

	UFUNCTION(BlueprintCallable, Category = AugmentedReality)
		void UpdateVideoFrame();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	void InitVideoMaterialTexture();

	FVector GetWorldLocationFromPixelCoordinates(FVector2D PixelCoordinates);

private:
	UPROPERTY()
		TArray<FColor> VideoFrameData;

	FUpdateTextureRegion2D *VideoTextureRegion;

	UMaterialInstanceDynamic *VideoMaterial;

	IVideoSource* VideoSource;
};
