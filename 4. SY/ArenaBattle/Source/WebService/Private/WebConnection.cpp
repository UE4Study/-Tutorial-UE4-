// Fill out your copyright notice in the Description page of Project Settings.

#include "WebService.h"
#include "WebConnection.h"

DEFINE_LOG_CATEGORY(WebConnection);

UWebConnection::UWebConnection()
{
	UE_LOG(WebConnection, Warning, TEXT("WebConnection Constructor Call!"));
	Host = TEXT("localhost:8000");
	URI = TEXT("/");
}

void UWebConnection::RequestToken(const FString& UserID)
{
	UE_LOG(WebConnection, Warning, TEXT("Request Token Call!"));

	TokenCompleteDelegate.Broadcast(TEXT("0LCJydGKiOil2a3NjVE9pTUNESVZWM05qVTlyUnlTln0.VJyMOicM"));
}