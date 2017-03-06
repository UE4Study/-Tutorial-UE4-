// Fill out your copyright notice in the Description page of Project Settings.

#include "WebService.h"
#include "WebConnection.h"

DEFINE_LOG_CATEGORY(WebConnection);

UWebConnection::UWebConnection()
{
	UE_LOG(WebConnection, Warning, TEXT("WebConnection Constructor Call!"));
}
