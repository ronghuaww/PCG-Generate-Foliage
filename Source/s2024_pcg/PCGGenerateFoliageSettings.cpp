// Fill out your copyright notice in the Description page of Project Settings.


#include "PCGGenerateFoliageSettings.h"

#include "PCGContext.h"
#include "PCGPin.h"
#include "Data/PCGSpatialData.h"
#include "Data/PCGPointData.h"
#include "Helpers/PCGAsync.h"
#include "Helpers/PCGHelpers.h"

#include "Math/RandomStream.h"

#define LOCTEXT_NAMESPACE "PCGGenerateFoliageSettings"

UPCGGenerateFoliageSettings::UPCGGenerateFoliageSettings()
{
    bUseSeed = true;
}

// void UPCGGenerateFoliageSettings::PostLoad()
// {
//     Super::PostLoad();
// }

FPCGElementPtr UPCGGenerateFoliageSettings::CreateElement() const
{
    return MakeShared<FPCGGenerateFoliageElement>();
}

bool FPCGGenerateFoliageElement::ExecuteInternal(FPCGContext *Context) const
{
    TRACE_CPUPROFILER_EVENT_SCOPE(FPCGTransformPointsElement::Execute);

    const UPCGGenerateFoliageSettings* Settings = Context->GetInputSettings<UPCGGenerateFoliageSettings>();
    check(Settings);

    const TArray<FPCGTaggedData> Inputs = Context->InputData.GetInputs();
    TArray<FPCGTaggedData>& Outputs = Context->OutputData.TaggedData;


    const FVector& Offset = Settings->Offset; 
    const int32 MinHeight = Settings->MinHeight; 
    const int32 MaxHeight = Settings->MaxHeight; 
    const double MinBend = Settings->MinBend;
    const double MaxBend = Settings->MaxBend;
    const double Decay = Settings->Decay;
    const bool RelativeScaling = Settings->RelativeScaling;

    return true;
}

#undef LOCTEXT_NAMESPACE
