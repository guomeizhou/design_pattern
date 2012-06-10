/* 单例模式(Singleton)
 * 特点：(1) 使用单例的类型只能产生一个实例。
 *       (2) 必须提供接口给外界调用，外界也只能通过调用该接口来得到实例。
 * 使用场景：当程序的整个生命周期中对于该类型只允许一个实例存在时。
 *           例如整个程序负责管理所有进程的manager。
 * 好处：(1) 保证了用户不产生两个及两个以上的实例。
 *       (2) 指分配一次内存，节省了内存，减少了内存碎片。
 */

#include <stdio.h>
#include <malloc.h>

typedef struct
{
    int nData;
} DataType;

static DataType s_instance3;
static DataType* s_pInstance4 = NULL;

DataType* GetInstance();
DataType* GetInstance2();
DataType* GetInstance3();
DataType* GetInstance4();

int main()
{
    DataType* pInstance = NULL;
    DataType* pInstance2 = NULL;
    DataType* pInstance3 = NULL;
    DataType* pInstance4 = NULL;

    pInstance = GetInstance();
    pInstance2 = GetInstance2();
    pInstance3 = GetInstance3();
    pInstance4 = GetInstance4();

    if (NULL != pInstance2)
    {
        free(pInstance2);
    }
    if (NULL != pInstance2)
    {
        free(pInstance4);
    }

    return 0;
}

DataType* GetInstance()
{
    static DataType instance;
    
    return &instance;
}

DataType* GetInstance2()
{
    static DataType* pInstance2 = NULL;

    if (NULL == pInstance2)
    {
        pInstance2 = (DataType*)malloc(sizeof(DataType));
    }
    return pInstance2;
}

DataType* GetInstance3()
{
    return &s_instance3;
}

DataType* GetInstance4()
{
    if (NULL == s_pInstance4)
    {
        s_pInstance4 = (DataType*)malloc(sizeof(DataType));
    }
    return s_pInstance4;
}
