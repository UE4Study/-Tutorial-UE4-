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

	//// 1-11
	//WebConnection->TokenCompleteDelegate.AddDynamic(this, &UABGameInstance::RequestTokenComplete);
	//WebConnection->RequestToken(TEXT("destiny"));

	//// 1-12
	//FString PackageName = TEXT("/Temp/SavedWebConnection");
	//UPackage* NewPackage = CreatePackage(nullptr, *PackageName);
	//WebConnectionNew = NewObject<UWebConnection>(NewPackage);
	//FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());

	//WebConnectionNew->Host = TEXT("127.0.0.7");
	//WebConnectionNew->URI = TEXT("/");
	//if (UPackage::SavePackage(NewPackage, WebConnectionNew, RF_Standalone, *PackageFileName))
	//{
	//	UPackage* SavedPackage = ::LoadPackage(NULL, *PackageFileName, LOAD_None);
	//	TArray<UObject*> ObjectsInPackage;
	//	GetObjectsWithOuter(SavedPackage, ObjectsInPackage, false);
	//	for (const auto& EachObject : ObjectsInPackage)
	//	{
	//		UWebConnection* WebConnectionFromFile = Cast<UWebConnection>(EachObject);
	//		if (WebConnectionFromFile)
	//		{
	//			AB_LOG(Warning, TEXT("WebConnection From File : Host %s, URI %s"), *WebConnectionFromFile->Host, *WebConnectionFromFile->URI);
	//		}
	//	}
	//}

	// 1-13
	// 1�ܰ�
	AB_LOG(Warning, TEXT("****** 1�ܰ� ******"));
	FHouse* NewHouseAddress = new FHouse();
	AB_LOG(Warning, TEXT("���� ���� �������ϴ�. ����ũ�� : %d"), NewHouseAddress->Size);
	if (NewHouseAddress)
	{
		delete NewHouseAddress;
		AB_LOG(Warning, TEXT("���� ���� ���� ö���߽��ϴ�. ��ũ�� : %d"), NewHouseAddress->Size);
		NewHouseAddress = nullptr;
	}

	// 2�ܰ�
	AB_LOG(Warning, TEXT("****** 2�ܰ� ******"));
	NewHouseAddress = new FHouse();
	NewHouseAddress->Size = 100;
	AB_LOG(Warning, TEXT("���� �ٽ� �������ϴ�. ��ũ�� : %d"), NewHouseAddress->Size);
	{
		TUniquePtr<FHouse> MyHouseDeed = TUniquePtr<FHouse>(NewHouseAddress);
		if (MyHouseDeed.IsValid())
		{
			AB_LOG(Warning, TEXT("�� ���� �� �ܵ����� �����Դϴ�. ����ũ�� : %d"), MyHouseDeed->Size);
		}

		//TUniquePtr<FHouse> FriendsHouseDeed = MyHouseDeed; // ������ ����! �ܵ� ������ ����
		TUniquePtr<FHouse> FriendHouseDeed = MoveTemp(MyHouseDeed);
		if (!MyHouseDeed.IsValid())
		{
			AB_LOG(Warning, TEXT("ģ������ ���� �Ⱦҽ��ϴ�. ģ����ũ�� : %d"), FriendHouseDeed->Size);
		}
	}

	AB_LOG(Warning, TEXT("�������� ������� ���� �ڵ����� ö�ŵǾ����ϴ�. ��ũ�� : %d"), NewHouseAddress->Size);

	// 3�ܰ�
	AB_LOG(Warning, TEXT("****** 3�ܰ� ******"));
	NewHouseAddress = new FHouse();
	NewHouseAddress->Size = 150.0f;
	AB_LOG(Warning, TEXT("���� �� �ٽ� �������ϴ�. ��ũ�� : %d"), NewHouseAddress->Size);
	{
		TSharedPtr<FHouse> MyHouseDeed = MakeShareable(NewHouseAddress); // ������� ���� ���Ŀ� ���
		if (MyHouseDeed.IsValid())
		{
			AB_LOG(Warning, TEXT("���� ���� ������ ���� �Ǿ����ϴ�. ����ũ�� : %d"), MyHouseDeed->Size);
			if (MyHouseDeed.IsUnique())
			{
				AB_LOG(Warning, TEXT("����� ȥ�� �����ϰ� �ֽ��ϴ�. ����ũ�� : %d"), MyHouseDeed->Size);
			}
		}

		TSharedPtr<FHouse> FriendsHouseDeed = MyHouseDeed;
		if (!FriendsHouseDeed.IsUnique())
		{
			AB_LOG(Warning, TEXT("ģ���� ���� ���������� �Ǿ����ϴ�. ģ����ũ�� : %d"), FriendsHouseDeed->Size);
		}

		MyHouseDeed.Reset(); // ���� �� �������� ������
		if (FriendsHouseDeed.IsUnique())
		{
			AB_LOG(Warning, TEXT("���� ģ���� ���� �����ϰ� �ֽ��ϴ�. ģ����ũ�� : %d"), FriendsHouseDeed->Size);
		}

		AB_LOG(Warning, TEXT("���� ���� �״�� �ֽ��ϴ�. ��ũ�� : %d"), NewHouseAddress->Size);
	}

	AB_LOG(Warning, TEXT("���� �ڵ� ö�ŵǾ����ϴ�. ��ũ�� : %d"), NewHouseAddress->Size);

	// 4�ܰ�
	AB_LOG(Warning, TEXT("****** 4�ܰ� ******"));
	NewHouseAddress = new FHouse();
	NewHouseAddress->Size = 200.0f;

	AB_LOG(Warning, TEXT("���� �ѹ� �� �ٽ� �������ϴ�. ù��°��ũ�� : %d"), NewHouseAddress->Size);

	FHouse* NewHouseAddress2 = new FHouse();
	NewHouseAddress2->Size = 250.0f;
	AB_LOG(Warning, TEXT("ģ���� ���� ���� �������ϴ�. �ι�°��ũ�� : %d"), NewHouseAddress2->Size);

	{
		TSharedPtr<FHouse> MyHouseDeed = MakeShareable(NewHouseAddress);
		AB_LOG(Warning, TEXT("�� ���� ���� �����մϴ�. ����ũ�� : %d"), MyHouseDeed->Size);
		TSharedPtr<FHouse> FriendHouseDeed = MakeShareable(NewHouseAddress2);
		AB_LOG(Warning, TEXT("ģ�� ���� ģ���� �����մϴ�. ģ����ũ�� : %d"), FriendHouseDeed->Size);

		MyHouseDeed->OthersDeed = FriendHouseDeed;
		AB_LOG(Warning, TEXT("ģ�� ���� ���� �����ϰ� ������ �� ���� �����մϴ�. ģ����ũ�� : %d"), MyHouseDeed->OthersDeed->Size);
		FriendHouseDeed->OthersDeed = MyHouseDeed;
		AB_LOG(Warning, TEXT("ģ���� �� ���� ���� �����ϰ� ������ �ڱ� ���� �����մϴ�. ����ũ�� : %d"), FriendHouseDeed->OthersDeed->Size);
	}

	AB_LOG(Warning, TEXT("�������� ������� ���� ���� ���� �ڵ� ö�ŵ��� �ʽ��ϴ�. ù��°��ũ�� : %d"), NewHouseAddress->Size);
	AB_LOG(Warning, TEXT("ģ���� ���� ���� �ڵ� ö�ŵ��� �ʽ��ϴ�. �ι�°��ũ�� : %d"), NewHouseAddress2->Size);

	NewHouseAddress->OthersDeed.Reset();
	AB_LOG(Warning, TEXT("ģ���� ���� ���� �������� ö���߽��ϴ�. ���ּҰ� �����־ �����Դϴ�. �ι�°��ũ�� : %d"), NewHouseAddress2->Size);
	AB_LOG(Warning, TEXT("�������� ���� ���� ���� �ڵ� ö�ŵ˴ϴ�. ù��°��ũ�� : %d"), NewHouseAddress->Size);

	// 5�ܰ�
	AB_LOG(Warning, TEXT("****** 5�ܰ� ******"));
	NewHouseAddress = new FHouse();
	NewHouseAddress->Size = 300.0f;
	AB_LOG(Warning, TEXT("���� ���������� ���� �����ϴ�. ù��°��ũ�� : %d"), NewHouseAddress->Size);

	NewHouseAddress2 = new FHouse();
	NewHouseAddress2->Size = 350.0f;
	AB_LOG(Warning, TEXT("ģ���� ���� �ٽ� �������ϴ�. �ι�°��ũ�� : %d"), NewHouseAddress2->Size);

	{
		TSharedPtr<FHouse> MyHouseDeed = MakeShareable(NewHouseAddress);
		AB_LOG(Warning, TEXT("�� ���� ���� �����մϴ�. ����ũ�� : %d"), MyHouseDeed->Size);
		TSharedPtr<FHouse> FriendHouseDeed = MakeShareable(NewHouseAddress2);
		AB_LOG(Warning, TEXT("ģ�� ���� ģ���� �����մϴ�. ģ����ũ�� : %d"), FriendHouseDeed->Size);

		MyHouseDeed->OthersDeed = FriendHouseDeed;
		AB_LOG(Warning, TEXT("ģ�� ���� ���� �����ϰ� ������ �� ���� �����մϴ�. ģ����ũ�� : %d"), MyHouseDeed->OthersDeed->Size);
		FriendHouseDeed->AccessHouse = MyHouseDeed;
		AB_LOG(Warning, TEXT("ģ���� �� �� ������ �����մϴ�. ����ũ�� : %d"), FriendHouseDeed->AccessHouse.Pin()->Size); // �������Ͱ� �����ϴ� Pin()�Լ��� ����ؼ� �׻� �������� ����� �Ǿ����� üũ
	}

	AB_LOG(Warning, TEXT("���� ���� ���� �ڵ� ö�ŵ˴ϴ�. ù��°��ũ�� : %d"), NewHouseAddress->Size);
	AB_LOG(Warning, TEXT("ģ���� ���� ���� �ڵ� ö�ŵ˴ϴ�. �ι�°��ũ�� : %d"), NewHouseAddress2->Size);

	// 6�ܰ�
	AB_LOG(Warning, TEXT("****** 6�ܰ� ******"));
	WebConnectionNew = NewObject<UWebConnection>();
	WebConnectionNew->Host = TEXT("127.0.0.1");
	//WebConnectionNew->AddToRoot();
	WebConnectionNew->ConditionalBeginDestroy();
	//GetWorld()->ForceGarbageCollection(true);
	GetWorld()->GetTimerManager().SetTimer(ObjectCheckTimer, this, &UABGameInstance::CheckUObjectAlive, 1.0f, true);
}

void UABGameInstance::CheckUObjectAlive()
{
	if (!WebConnectionNew)
	{
		AB_LOG(Warning, TEXT("�𸮾������Ʈ�� ���Դϴ�."));
		return;
	}

	if (!WebConnectionNew->IsValidLowLevel())
	{
		AB_LOG(Warning, TEXT("�𸮾� ������Ʈ�� ��ȿ���� �ʽ��ϴ�."));
		return;
	}

	AB_LOG(Warning, TEXT("�𸮾� ������Ʈ�� ���� ����ֽ��ϴ�. : %s"), *WebConnection->Host);
}
