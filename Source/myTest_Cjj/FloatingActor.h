// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"					//ue4��������
#include "GameFramework/Actor.h"			//����Actor����
#include "FloatingActor.generated.h"		//��һ��һ��Ҫ��ͷ�ļ�������

UCLASS()									//����� �ܹ������ʶ��
class MYTEST_CJJ_API AFloatingActor : public AActor
{
	GENERATED_BODY()						//���滻
	
public:
    // ���ô�Actor���Ե�Ĭ��ֵ
    AFloatingActor();

    //�������������༭������ͼ
    //VisibleAnywhere ���η����ø�����Ϊ�κεط����ɼ�
    UPROPERTY(VisibleAnywhere)
        UStaticMeshComponent* VisualMesh;

protected:
    // ��Ϸ��ʼʱ������ʱ����
    virtual void BeginPlay() override;

public:
    // ��֡����
    virtual void Tick(float DeltaTime) override;

};
