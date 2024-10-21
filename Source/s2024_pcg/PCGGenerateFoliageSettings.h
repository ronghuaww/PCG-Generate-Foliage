// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PCGSettings.h"
#include "PCGGenerateFoliageSettings.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, ClassGroup = (Procedural))
class S2024_PCG_API UPCGGenerateFoliageSettings : public UPCGSettings
{
	GENERATED_BODY()
	
public:
	UPCGGenerateFoliageSettings();

	//~Begin UObject interface
	// virtual void PostLoad() override;
	//~End UObject interface

	//~Begin UPCGSettings interface
	#if WITH_EDITOR
	virtual FName GetDefaultNodeName() const override { return "GenerateFoliageElements"; }
	virtual FText GetDefaultNodeTitle() const override { return NSLOCTEXT("PCGGenerateFoliageSettings", "NodeTitle", "Generate Foliage Elements"); }
	virtual FText GetNodeTooltipText() const override { return FText::FromString("Generate random foliage leaves given certain ranges."); }
	virtual FLinearColor GetNodeTitleColor() const override { return FLinearColor(0.388235f, 0.596078f, 0.176471f, 1.0f); }
	virtual EPCGSettingsType GetType() const override { return EPCGSettingsType::Spawner; }
#endif

protected:
	virtual TArray<FPCGPinProperties> InputPinProperties() const override { return Super::DefaultPointInputPinProperties(); }
	virtual TArray<FPCGPinProperties> OutputPinProperties() const override { return Super::DefaultPointOutputPinProperties(); }
	virtual FPCGElementPtr CreateElement() const override;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta=(PCG_Overridable))
	FVector Offset;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta=(PCG_Overridable))
	int32 MinHeight = 2;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta=(PCG_Overridable))
	int32 MaxHeight = 5;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta=(PCG_Overridable))
	double MinBend = 0.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta=(PCG_Overridable))
	double MaxBend = 0.0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta=(PCG_Overridable))
	double Decay = 0;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Settings, meta=(PCG_Overridable))
	bool RelativeScaling = false;
	
};

class FPCGGenerateFoliageElement : public IPCGElement
{
protected:
	virtual bool ExecuteInternal(FPCGContext* Context) const override;
};


