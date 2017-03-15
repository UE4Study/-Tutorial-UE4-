// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaBattle.h"
#include "ABGameInstance.h"

UABGameInstance::UABGameInstance()
{
	AB_LOG(Warning, TEXT("Constructor Start!"));
	WebConnection = CreateDefaultSubobject<UWebConnection>(TEXT("MyWebConnection"));
	AB_LOG(Warning, TEXT("Constructor End!"));
}

void UABGameInstance::RequestTokenComplete(const FString& Token)
{
	AB_LOG(Warning, TEXT("Token : %s"), *Token);
}

void UABGameInstance::Init()
{
	Super::Init();
	AB_LOG_CALLONLY(Warning);

	// 1-6
	//UClass* ClassInfo1 = WebConnection->GetClass();
	//UClass* ClassInfo2 = UWebConnection::StaticClass();
	//if (ClassInfo1 == ClassInfo2)
	//{
	//	AB_LOG(Warning, TEXT("ClassInfo1 is same with ClassInfo2"));
	//}

	//for (TFieldIterator<UProperty> It(ClassInfo1); It; ++It)
	//{
	//	AB_LOG(Warning, TEXT("Field : %s, Type : %s"), *It->GetName(), *It->GetClass()->GetName());
	//	UStrProperty* StrProp = FindField<UStrProperty>(ClassInfo1, *It->GetName());
	//	if (StrProp)
	//	{
	//		AB_LOG(Warning, TEXT("Value = %s"), *StrProp->GetPropertyValue_InContainer(WebConnection));
	//	}
	//}

	//for (const auto& Entry : ClassInfo1->NativeFunctionLookupTable)
	//{
	//	AB_LOG(Warning, TEXT("Function = %s"), *Entry.Name.ToString());
	//	UFunction* Func1 = ClassInfo1->FindFunctionByName(Entry.Name);
	//	if (Func1->ParmsSize == 0)
	//	{
	//		WebConnection->ProcessEvent(Func1, NULL);
	//	}
	//}

	// 1-7
	//TArray<UObject*> DefaultSubobjects;
	//GetDefaultSubobjects(DefaultSubobjects);
	//for (const auto& Entry : DefaultSubobjects)
	//{
	//	AB_LOG(Warning, TEXT("DefaultSubobject : %s"), *Entry->GetClass()->GetName());
	//	AB_LOG(Warning, TEXT("Outer of DefaultSubobject : %s"), *Entry->GetOuter()->GetClass()->GetName());	// �ܺ�����
	//}

	//WebConnectionNew = NewObject<UWebConnection>(this);
	//AB_LOG(Warning, TEXT("Outer of NewObject : %s"), *WebConnectionNew->GetOuter()->GetClass()->GetName());

	//UWorld* CurrentWorld = GetWorld();
	//for (const auto& Entry : FActorRange(CurrentWorld))	// For Ranged Loop ����
	//{
	//	AB_LOG(Warning, TEXT("Actor : %s"), *Entry->GetName());
	//	TArray<UObject*> Components;
	//	Entry->GetDefaultSubobjects(Components);
	//	for (const auto& CEntry : Components)
	//	{
	//		AB_LOG(Warning, TEXT(" -- Component : %s"), *CEntry->GetName());
	//	}
	//}

	//for (TActorIterator<AStaticMeshActor> It(CurrentWorld); It; ++It)	// ���� �߿����� ���ϴ� Ÿ�Ը� �����ؼ� ����� ������ �̾Ƴ� �� �־ ��κ� ���� ����ϴ� ���
	//{
	//	AB_LOG(Warning, TEXT("StaticMesh Actor : %s"), *It->GetName());
	//}

	//WebConnection->Host = TEXT("localhost");
	//WebConnectionNew->Host = TEXT("127.0.0.1");

	//for (TObjectIterator<UWebConnection> It; It; ++It) // ���͸� ������ ���� ���忡 �ε��� ��� �𸮾� ������Ʈ�� �������� ���ؼ� ���
	//{
	//	UWebConnection* Conn = *It;
	//	AB_LOG(Warning, TEXT("WebConnection Object Host : %s"), *Conn->Host);
	//}

	// 1-11
	WebConnection->TokenCompleteDelegate.AddDynamic(this, &UABGameInstance::RequestTokenComplete);
	WebConnection->RequestToken(TEXT("destiny"));

	// 1-12
	FString PackageName = TEXT("/Temp/SavedWebConnection");
	UPackage* NewPackage = CreatePackage(nullptr, *PackageName);
	WebConnectionNew = NewObject<UWebConnection>(NewPackage);
	FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());

	WebConnectionNew->Host = TEXT("127.0.0.7");
	WebConnectionNew->URI = TEXT("/");
	if (UPackage::SavePackage(NewPackage, WebConnectionNew, RF_Standalone, *PackageFileName))
	{
		UPackage* SavedPackage = ::LoadPackage(NULL, *PackageFileName, LOAD_None);
		TArray<UObject*> ObjectsInPackage;
		GetObjectsWithOuter(SavedPackage, ObjectsInPackage, false);
		for (const auto& EachObject : ObjectsInPackage)
		{
			UWebConnection* WebConnectionFromFile = Cast<UWebConnection>(EachObject);
			if (WebConnectionFromFile)
			{
				AB_LOG(Warning, TEXT("WebConnection From File : Host %s, URI %s"), *WebConnectionFromFile->Host, *WebConnectionFromFile->URI);
			}
		}
	}
}


