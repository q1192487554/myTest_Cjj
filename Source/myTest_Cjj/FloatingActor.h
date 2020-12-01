// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"					//ue4核心内容
#include "GameFramework/Actor.h"			//包含Actor父类
#include "FloatingActor.generated.h"		//这一行一定要在头文件最下面

UCLASS()									//标记类 能够被虚幻识别
class MYTEST_CJJ_API AFloatingActor : public AActor
{
	GENERATED_BODY()						//宏替换
	
public:
    // 设置此Actor属性的默认值
    AFloatingActor();

    //将变量公开到编辑器或蓝图
    //VisibleAnywhere 修饰符设置该属性为任何地方都可见
    UPROPERTY(VisibleAnywhere)
        UStaticMeshComponent* VisualMesh;

protected:
    // 游戏开始时或生成时调用
    virtual void BeginPlay() override;

public:
    // 逐帧调用
    virtual void Tick(float DeltaTime) override;

};
